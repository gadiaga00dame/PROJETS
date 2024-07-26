function y=EIm(y0,h,T,A,b)
    d=size(b,1); 
    N=floor(T/h);
    y=[y0];
    yy=y0;
    for i=1:N
        yy=inv(eye(d,d)-h*A)*(yy+h*b); 
        y=[y yy];
    end
end
