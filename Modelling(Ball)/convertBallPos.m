function [x,y] = convertBallPos(X,Y)
    amp = 221;
    midX = (514+75)/2;
    midY = (464+21)/2;
    y = 0.2*(X-midX)/amp;
    x = 0.2*(Y-midY)/amp;
end