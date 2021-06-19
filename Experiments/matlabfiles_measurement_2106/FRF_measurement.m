fmin = 1;
fmax = 300;
fres = 0.5;
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

M = 2;                     % number of realisations random phase multisine
P = 10;                     % number of consecutive periods

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

sf = 0.0068;                                 % scaling factor

for ii=1:M
    
    u0 = sf*CalcMultisine(ExcitedHarm, N);
    
    U = fft(u0)/sqrt(N);

    % collect measurements
    Uall(ii,:,:) = repmat((U(MeasHarm+1)).', P, 1);
    
    u = repmat(u0,P,1);
    save(['u_' num2str(ii)],'u');
   
end

MeasHarm = round(freqmeas/(fs/N));
save('variables','Uall','ExcitedHarm','MeasHarm','fs','N','Spacing','M','K');


%% lookup table shit

load('u_1.mat');
LUTObj = Simulink.LookupTable;
LUTObj.Table.Value = u;
t=0:0.001:20;
t=t(1:end-1);
t=t';
LUTObj.Breakpoints(1).Value = t;
LUTObj.StructTypeInfo.Name = 'myLUTStruct';

LUTObj.CoderInfo.StorageClass = 'Custom';
LUTObj.CoderInfo.CustomStorageClass = 'Struct';
LUTObj.CoderInfo.CustomAttributes.StructName = 'xdir';
