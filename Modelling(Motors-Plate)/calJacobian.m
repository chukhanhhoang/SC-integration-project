function jacobian = calJacobian(f,x)
    jacobian = sym('temp',[length(f),length(x)]);

    for i = 1:length(f)
        jacobian(i,:) = partialdiff(f(i),x);
    end
end