function [R, P, K] = CalcResidue(B, A, Plane);%%%		B(x)       R(1)       R(2)             R(n)%       ----  =  -------- + -------- + ... + -------- + K(x)%       A(x)      y- P(1)   y - P(2)         y - P(n)%%		x, y = s, sqrt(s) for Plane = 's', 'w'%		x = z^-1, y = z for Plane = 'z'%%	[R, P, K] = CalcResidue(B, A, Plane);%%%	Output parameters%%		R		=	Residue matrix, size ny x nu%		P		=	Poles B(x)/A(x) = roots A(x) polynomial%		K		= 	polynomial; is zero if nb < na%%	Input parametera%%		B		=	ny x nu matrix polynomial; size ny x nu x (nb+1)%		A		=	polynomial; size 1 x (na+1)%		Plane	=	defines the domain%					's':	continuous-time systems%					'w':	sqrt(s) diffusion systems%					'z':	discrete-time systems%%% Copyright (c) Rik Pintelon, Vrije Universiteit Brussel - dept. ELEC, January 2005 % All rights reserved.% Software can be used freely for non-commercial applications only.%[ny, nu, nb] = size(B);nb = nb - 1;na = length(A) - 1;R = zeros(ny, nu, na);P = zeros(na, 1);K = zeros(ny, nu, nb-na+1);for ii = 1:ny	for jj = 1:nu		[R1, P1, K1] = residue(fliplr(squeeze(B(ii,jj,:)).'), fliplr(A));		R(ii, jj, :) = R1.';		P = P1;		K(ii, jj, :) = fliplr(K1);	endend