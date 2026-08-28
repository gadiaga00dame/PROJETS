%SERIGN DAME GADIAGA TT OCS/MATLAB

%partie 1

  f=inline('-150*y+30');
 
  y0=1/5;
  T=1;
 
  h=0.02;
  t1=0:h:T;
  y1=EEx(y0,h,T,f);
  
  h=0.01;
  t2=0:h:T;
  y2=EEx(y0,h,T,f);
  
  h=0.001;
  t3=0:h:T;
  y3=EEx(y0,h,T,f);
 
   figure(1)
   subplot(1,3,1)
   plot(t1,y1,'r-')
   legend('Pour h=0.02')
   
   subplot(1,3,2)
   plot(t2,y2,'b-')
   legend('Pour h=0.01')
   
   subplot(1,3,3)
   plot(t3,y3,'g-')
   legend('Pour h=0.001')

   epsilon=10e-10;
   y0=1/5+epsilon;
   T=1;
  
  h=0.02;
  t1=0:h:T;
  y1=EEx(y0,h,T,f);
  
  h=0.01;
  t2=0:h:T;
  y2=EEx(y0,h,T,f);
  
  h=0.001;
  t3=0:h:T;
  y3=EEx(y0,h,T,f);
 
  
   figure(2)
   subplot(1,3,1)
   plot(t1,y1,'r-')
   legend('Pour h=0.02')
   
   subplot(1,3,2)
   plot(t2,y2,'b-')
   legend('Pour h=0.01')
   
   subplot(1,3,3)
   plot(t3,y3,'g-')
   legend('Pour h=0.001')
 
   
   








