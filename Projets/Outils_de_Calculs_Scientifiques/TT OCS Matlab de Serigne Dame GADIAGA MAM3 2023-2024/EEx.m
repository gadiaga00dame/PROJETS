function y=EEx(y0,h,T,f)
    N=floor(T/h);
    y=[y0];yy=y0;
    for i=1:N
        yy=yy+h*feval(f,yy); y=[y yy];
    end
end