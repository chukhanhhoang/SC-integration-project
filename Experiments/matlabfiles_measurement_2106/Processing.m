%% Processing

for k = 1:M
    y1 = load(['y_' num2str(k)]);
    y = y.y;
    Y = fft(y)/sqrt(N);
    Yall(ii,:,:) = repmat((Y(MeasHarm+1)).', P, 1);
end

[Y, Yc, U, G, freq] = Fast_NL_Anal(Yall, Uall, ExcitedHarm, MeasHarm, fs, N);

Plot_Fast_NL_Anal(Y, Yc, U, G, freq, Spacing);
