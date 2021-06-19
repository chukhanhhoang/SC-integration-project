function RandomPhaseMultisine = Function5SC26(timestamp)

fmin = 1;
fmax = 500;
fres = 1;
fs = 1000;
frat = 1;
Nblock = 3;
Spacing = 'log';

TypeMultisine = 'full';

DefFreq.fmin = fmin;
DefFreq.fmax = fmax;
DefFreq.fs = fs;
DefFreq.fres = fres;
DefFreq.frat = frat;
[ExcitedHarm, N, NewDefFreq] = HarmMultisine(DefFreq, Nblock, Spacing, TypeMultisine);

M = 1;                     % number of realisations random phase multisine
P = 20;                     % number of consecutive periods

freqall = ([0:1:N-1]*fs/N).';               % all DFT frequencies over full unit circle
qall = exp(-sqrt(-1)*2*pi*freqall/fs);      % z^-1 over full unit circle
qOdE = exp(-sqrt(-1)*2*pi*ExcitedHarm/N);   % z^-1 at odd excited frequencies
fstart = fmin;                              % first measured frequency
fstop = fmax;

freqmeas = ([fstart:fres:fstop]).';         % all measured frequencies

MeasHarm = freqmeas/(fs/N);                 % measured harmonics
Fall = length(MeasHarm);                    % number of measured frequencies
Uall = zeros(M, P, Fall);                   % all input spectra at the measured frequencies
Yall = zeros(M, P, Fall);                   % all output spectra at the measured frequencies
waittime = zeros(fs*8,1);                           % waiting period
u = [];
sf = 0.6;

for ii=1:M
    
    u0 = sf*CalcMultisine(ExcitedHarm, N);

    

    U = fft(u0)/sqrt(N);

    % collect measurements
    Uall(ii,:,:) = repmat((U(MeasHarm+1)).', P, 1);
   
end

u1 = repmat(u0,P,1);

t = 0:1/fs:27.999;
u2 = [waittime; u1]';
u = [timestamp; u2];

save(['u_' num2str(ii)],'u');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Required variables:                                                    %
%   ExcitedHarm     =   excited odd harmonics in multisine               %
%                           size: F x 1                                  %
%   MeasHarm        =   all measured harmonics                           %
%                           size: Fall x 1                               %
%   N               =   number of samples in one period of the multisine %
%   fs              =   sampling frequency                               %
%   Uall, Yall      =   M x P X Fall input output spectra where          %
%                           M = number of realisations multisine         %
%                           P = number of consecutive periods multisine  %
%                           Fall = number of all measured frequencies    %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% calculation of all measured harmonics
MeasHarm = round(freqmeas/(fs/N));

function TheSignal = CalcMultisine(ExcitedHarm, N, AmplExcitedHarm);
%
%       TheSignal = CalcMultisine(ExcitedHarm, N, AmplExcitedHarm)
%
%       Calculates one period of a random phase multisine with rms value equal to 1
%
%   OUTPUT
%       TheSignal           =	one period of the time domain signal
%                               rms value equals one 
%
%   INPUT
%       ExcitedHarm         =	excited harmonics of the multisine expressed in harmonic number
%       N                   =	number of time domain samples in one period
%       AmplExcitedHarm     =   optional parameter: amplitudes of the excited harmonics; 
%                               default value: uniform
%
% Copyright (c) Rik Pintelon, Vrije Universiteit Brussel - dept. ELEC, March 2006 
% All rights reserved.
% Software can be used freely for non-commercial applications only.
% Version October 2009
%

if nargin == 2
    AmplExcitedHarm = ones(size(ExcitedHarm));
end % if no amplitudes are given

% calculation time domain signal
S = zeros(N,1);
S(ExcitedHarm + 1) = AmplExcitedHarm .* exp(sqrt(-1)*2*pi*rand(size(ExcitedHarm)));
TheSignal = 2*real(ifft(S));
TheSignal = TheSignal/rms(TheSignal);  % rms value = 1

function [ExcitedHarm, N, NewDefFreq] = HarmMultisine(DefFreq, Nblock, Spacing, TypeMulti);
%
%       function [ExcitedHarm, N, NewDefFreq] = HarmMultisine(DefFreq, Nblock, Spacing, TypeMulti);
%
%       calculates the harmonic content of an odd or full random harmonic grid multisine signal
%       with a linear or a logarithmic spacing in the band defined by [fmin, fmax]
%       for a lowpass design
%           fmin = fres/2	for odd multisines
%           fmin = fres     for full multisines
%       where
%           fres =          the frequency spacing between two consecutive odd harmonics for odd multisines 
%           fres =          the frequency spacing between two consecutive harmonics for full multisines 
%
%
%   OUTPUT
%
%       ExcitedHarm     =   excited frequencies of the multisine expressed in harmonic numbers
%
%       N               =   number of time domain samples in one period
%
%       NewDefFreq      =   struct containing the information about the sampling frequency, frequency resolution,
%                           and the excited frequency band {'fs', 'fmin', 'fmax', 'fres', 'frat'}
%                               NewDefFreq.fs      =    sampling frequency of the generator (remains unchanged!)
%                               NewDefFreq.fres    =    frequency spacing in Hz between the (odd) harmonics 
%                                                       fres is modified such that fs/fres is an integer number
%                                                       Note: not all (odd) harmonics are excited; especially for the log spacing
%                               NewDefFreq.fmin    =    lowest excited frequency in Hz
%                                                       fmin is modified such that fmin/fres is an (odd) integer number
%                                                       (for lowpass design fmin = fres/2)
%                               NewDefFreq.fmax    =    largest excited frequency in Hz
%                                                       fmax is modified such that fmax/fres is an (odd) integer number
%
%   INPUT
%
%       DefFreq         =   struct containing the information about the sampling frequency, frequency resolution,
%                           and the excited frequency band {'fs', 'fmin', 'fmax', 'fres', 'frat'}
%                               DefFreq.fs      =   sampling frequency of the generator
%                               DefFreq.fres    =   frequency spacing in Hz between the (odd) harmonics 
%                               DefFreq.fmin    =   lowest excited frequency in Hz
%                                                   (for lowpass design of odd multisines fmin = fres/2)
%                               DefFreq.fmax    =   largest excited frequency in Hz
%                               DefFreq.frat    =   ratio between consecutive (odd) harmonics for a logarithmic frequency spacing
%
%       Nblock          =   size of the group of consecutive (odd) harmonics where one is randomly eliminated
%                           if Nblock = Inf then no detection lines are present 
%
%       Spacing         =   linear or logarithmic frequency spacing; optional parameter (default = 'linear') 
%                               'lin', 'linear':       linear frequency spacing
%                               'log', 'logarithmic':  quasi logarithmic frequency spacing (rounded to DFT grid)
%
%       TypeMulti       =   type multisine; optional (default = 'odd')
%                               'odd':   odd random harmonic grid multisine        
%                               'full':  full random harmonic grid multisine 
%
% Copyright (c) Rik Pintelon, Vrije Universiteit Brussel - dept. ELEC, March 2006 
% All rights reserved.
% Software can be used freely for non-commercial applications only.
% Version 4 December 2007
%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% initialize the variables %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%

fs = DefFreq.fs;
fres = DefFreq.fres;
fmin = DefFreq.fmin;
fmax = DefFreq.fmax;

if isfield(DefFreq, 'frat')
	if ~isempty(DefFreq.frat)
        frat = DefFreq.frat;
	end % if not empty
end % if isfield

% type of the frequency spacing
if nargin == 2
    Spacing = 'lin';
end % if
Spacing = lower(Spacing);

% type of the multisine
if nargin <= 3
    TypeMulti = 'odd';
end % if
TypeMulti = lower(TypeMulti);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% calculation odd random harmonic grid %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

if strcmp(TypeMulti, 'odd')
    fres = fres/2;                  % frequency spacing between odd and even harmonics
end % if odd multisine
N = ceil(fs/fres);                  % number of time domain points in one period
fres = fs/N;
FreqSpan = floor(fmax/fres);        % frequency span for a lowpass signal

% calculate the (odd) random harmonic numbers for a lowpass signal
switch Spacing
    
    case {'lin', 'linear'}				
		ExcitedHarm = lintone(FreqSpan, Nblock, TypeMulti);
		
    case {'log', 'logarithmic'}
        ExcitedHarm = logtone(FreqSpan, frat, Nblock, TypeMulti);
        
end % switch Spacing

% convert lowpass in bandpass
FirstNonZeroHarm = ceil(fmin/fres);
RemoveHarm = find(ExcitedHarm < FirstNonZeroHarm);
ExcitedHarm(RemoveHarm) = [];


%%%%%%%%%%%%%%%%%%%%%%%%
% realised frequencies %
%%%%%%%%%%%%%%%%%%%%%%%%

NewDefFreq.fs = fs;
NewDefFreq.fres = fres;
if strcmp(TypeMulti, 'odd')
    NewDefFreq.fres = 2*NewDefFreq.fres;       % frequency spacing between the odd harmonics
end % if odd multisine
NewDefFreq.fmin = ExcitedHarm(1)*fres;
NewDefFreq.fmax = ExcitedHarm(end)*fres;

function [fqlog, df, cdmax, freqind] = lin2log(freqv, rf)
%LIN2QLOG Quasilogarithmic subset of a linear frequency grid.
%
%       [fqlog, df, cdmax, freqind] = lin2log(freqv, rf)
%
%       The routine starts from a linear frequency grid, given in freqv, and
%       selects a quasi-logarithmic set, providing that the ratio of successive
%       frequencies is about  rf (or larger, if the frequency vector is not
%       dense enough).
%
%       Algorithm: starting from the first non-zero frequency point, the next
%       point f2 will be the one in freqv, closest to f1*rf, and larger than
%       f1. The points between f1 and f2 are deleted. This is repeated until
%       the end of the file: the last point will only be taken if the last
%       frequency is larger than f(n-1)*sqrt(rf).
%
%       Output arguments:
%       fqlog   =   quasi-log frequency vector (column vector)
%       df      =   minimum common divider of the values in freqv
%                   The harmonic numbers in fqlog can be calculated as
%                   harmno = round(fqlog/df);
%       cdmax   =   maximum common divider of the harmonic numbers
%       freqind =   column vector, indices of the selected
%                   frequency points in freqv
%
%       Input arguments:
%       freqv   =   strictly monotonic increasing frequency vector
%                   (usually with constant increments)
%       rf      =   desired frequency ratio
%
%       Usage: [fqlog, df, cdmax, freqind] = lin2qlog(freqv, rf);
%       Example: fqlog = lin2qlog([1:128], sqrt(2));
%
%       See also: LOG2QLOG, LOGSPACE.

%       Copyright (c) I. Kollar and Vrije Universiteit Brussel, ELEC, 1991-2003
%       All rights reserved.
%       $Revision: $
%       Last modified: 30-Dec-2003
%       Line 70 modified by Rik Pintelon: 25 March 2008

error(nargchk(1,2,nargin))
if min(size(freqv))>1, error('freqv is not a vector'), end
freqv=freqv(:); %column vector
if any(imag(freqv)), error('freqv is complex'), end
if any(freqv<0), error('freqv contains negative elements'), end
if any(diff(freqv)<=0), error('freqv is not strictly increasing'), end
if length(rf)~=1, error('rf is not scalar'), end
if rf<=0, error('rf is not positive'), end
%
freqvnz=freqv; if freqvnz(1)==0, freqvnz(1)=[]; end
dfv=diff([0;freqvnz]); df=min(dfv);
remfnegl=max(freqv)/df*eps*max(freqv);
while any(dfv>remfnegl)
  df0=df; df=min([df0;dfv]);
  dfv=sort(rem([df0;dfv],df));
  remfnegl=max(freqv)/df*eps*max(freqv);
  ind=find(dfv<=remfnegl); dfv(ind)=[];
end
%
if freqv(1)~=0
  lastind=1; freqind(1)=1; fqlog(1)=freqv(1);
else
  lastind=2; freqind(1)=2; fqlog(1)=freqv(2);
end
while lastind<length(freqv), %process until end of vector
  [m,nextind]=min(abs(freqv(lastind)*rf-freqv(lastind+1:length(freqv))));
  lastind=lastind+nextind;
%   if freqv(lastind)>fqlog(length(fqlog))*sqrt(rf),
  if freqv(lastind)>fqlog(length(fqlog))*rf^0.7,
    %step is acceptably large
    freqind=[freqind;lastind]; fqlog=[fqlog;freqv(lastind)];
  end
end %while
cdmax=1;
if nargout>1
  if max(freqv)/df>1e6
    disp(sprintf(['WARNING: maximum harmonic index found in ''lin2log''\n',...
            '   is %.0f, with df = %.3g Hz, T = %.3g s'],...
            round(max(freqv)/df),df,1/df))
    disp('Large indexes are often due to inaccurately given frequency values.')
    disp('If this is the case, before invoking msinclip do')
    disp('   freqv = round(freqv*T)/T;')
    disp('where T is the desired period length.')
    disp(' ')
  end
  harmno=round(fqlog/df); if harmno(1)==0, harmno(1)=[]; end
  for ind=2:min(harmno), if all(rem(harmno,ind)==0), cdmax=ind; end, end
end
%%%%%%%%%%%%%%%%%%%%%%%% end of lin2qlog %%%%%%%%%%%%%%%%%%%%%%%%

function y = rms(x, dim);
%
%   function y = rms(x, dim);
%
%   OUTPUT
%
%       y       =   rms value of x along the dimension dim
%
%
%   INPUT
%
%       x       =   matrix containing the signal
%       dim     =   Optional parameter: dimension of the matrix along which the rms value is calculated 
%                   Default: dim = 1
%
%   Rik Pintelon, October 2009
%

try
    if isempty(dim)
        dim = 1;
    end % empty Gc
catch
    dim = 1;
end % try

y = mean(abs(x.^2), dim).^0.5;

function ExcitedHarm = logtone(FreqSpan, FreqRatio, Nblock, TypeMulti);
%
%	ExcitedHarm = logtone(FreqSpan, FreqRatio, Nblock, TypeMulti);
%
%		(odd) multisine with logaritmic frequency distribution and randomly
%		distributed (odd) detection lines.
%		calculates a logarithmic distributed frequency grid of (odd) harmonics
%		where one (odd) harmonic out of Nblock consecutive harmonics is left out		
%
%	OUTPUT PARAMETERS
%
%		ExcitedHarm		= vector containing the excited harmonics
%
%	INPUT PARAMETERS
%
%		FreqSpan		=   ratio fmax/fmin
%		FreqRatio		=   ratio consecutive odd frequencies in logtone
% 		Nblock			=   number of lines per block
%                           if Nblock = Inf then no detection lines are present 
%       TypeMulti       =   type multisine; optional (default = 'odd')
%                               'odd':   odd random harmonic grid multisine        
%                               'full':  full random harmonic grid multisine 
%
% Johan Schoukens and Rik Pintelon, September 2003
% Version March 18, 2008
%

% type of the multisine
if nargin == 3
    TypeMulti = 'odd';
end % if
TypeMulti = lower(TypeMulti);

% selection of the frequency span
switch TypeMulti    
    case 'odd', Fmax = FreqSpan/2;
    case 'full', Fmax = FreqSpan;        
end % switch

% resolution of the frequency axis = fmin 
% => total number of frequencies on the linear grid = FreqSpan = fmax/fmin

freqv = [1:Fmax];
ExcitedHarm = lin2log(freqv, FreqRatio);		% generates a full quasi log frequency grid

if ~isinf(Nblock)
    Nlog = length(ExcitedHarm);
    NEmpty = floor((Nlog-Nblock)/Nblock);			% number of detection lines 
    ss = floor(Nblock*rand(NEmpty+1,1)) + 1;        % random choice of integer numbers from 1:1:Nblock
    dummy = [0:NEmpty]'*Nblock + ss;
    ExcitedHarm(dummy) = [];
end % if not Nblock = inf

if strcmp(TypeMulti, 'odd')
    ExcitedHarm = 2*ExcitedHarm - 1;			% no even harmonics
end % if odd multisine




