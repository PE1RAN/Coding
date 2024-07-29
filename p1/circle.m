function[]=circle(a,b,color)
r=0.7;
alpha=0:pi/1800:2*pi;
x=a+r*cos(alpha);
y=b+r*sin(alpha);
fill(x,y,color);
hold on;
end