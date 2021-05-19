function ret = partialdiff(f,x)
    n = length(x);
    ret = sym('temp',[1,n]);
    for i = 1:n
        ret(i)=diff(f,x(i));
    end
end