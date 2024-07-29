%project 1
clf
w=input('The width of the road:');
o=input('The time of orange light:');
g=input('The time of green light:');
r=input('The time of red light:');
p=input('The possibility of ignoring the traffic light:');
n=input('The quantity of cars:');
fill([-10 -10 30+w 30+w],[-10 30+w 30+w -10],'k');
hold on;
line1([0 10 10],[10 10 0]);
line1([0 10 10],[10+w 10+w 20+w]);
line1([10+w 10+w 20+w],[0 10 10]);
line1([10+w 10+w 20+w],[20+w 10+w 10+w]);
line2([0 10],[10+w/2 10+w/2]);
line2([10+w 20+w],[10+w/2 10+w/2]);
line2([10+w/2 10+w/2],[0 10]);
line2([10+w/2 10+w/2],[10+w 20+w]);
circle(9.3,9.3,'g');
circle(10.7+w,10.7+w,'g');
circle(9.3,10.7+w,'r');
circle(10.7+w,9.3,'r');
safe=true;
st=1;
rd=0;
x0=[0 0 3 3];
y=[10.2 9.8+w/2 9.8+w/2 10.2];
xx0=[17+w 17+w 20+w 20+w];
yy=[10.2+w/2 9.8+w 9.8+w 10.2+w/2];
xxx=[10.2+w/2 9.8+w 9.8+w 10.2+w/2];
yyy0=[0 0 3 3];
xxxx=[10.2 9.8+w/2 9.8+w/2 10.2];
yyyy0=[17+w 17+w 20+w 20+w];
for i=0:0.01:3.5
    x=x0+i;
    xx=xx0-i;
    yyy=yyy0+i;
    yyyy=yyyy0-i;
    A=fill(x,y,'b');
    AA=fill(xx,yy,'c');
    AAA=fill(xxx,yyy,'m');
    AAAA=fill(xxxx,yyyy,'y');
    set(A,'xdata',x,'ydata',y)
    set(AA,'xdata',xx,'ydata',yy)
    set(AAA,'xdata',xxx,'ydata',yyy)
    set(AAAA,'xdata',xxxx,'ydata',yyyy)
    pause(0.01)
end
x0=x0+3.5;
xx0=xx0-3.5;
yyy0=yyy0+3.5;
yyyy0=yyyy0-3.5;
a0=[0 0 3 3];
b=[10.2 9.8+w/2 9.8+w/2 10.2];
aa0=[17+w 17+w 20+w 20+w];
bb=[10.2+w/2 9.8+w 9.8+w 10.2+w/2];
aaa=[10.2+w/2 9.8+w 9.8+w 10.2+w/2];
bbb0=[0 0 3 3];
aaaa=[10.2 9.8+w/2 9.8+w/2 10.2];
bbbb0=[17+w 17+w 20+w 20+w];
box1={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
box2={'1','2','3','4','5','6','7','8','9','0'};
plateA=[box1{randi(26,1,1)},'',box2{randi(10,1,1)},box2{randi(10,1,1)},box1{randi(26,1,1)},box1{randi(26,1,1)},box2{randi(10,1,1)}];
plateAA=[box1{randi(26,1,1)},'',box2{randi(10,1,1)},box2{randi(10,1,1)},box1{randi(26,1,1)},box1{randi(26,1,1)},box2{randi(10,1,1)}];
plateAAA=[box1{randi(26,1,1)},'',box2{randi(10,1,1)},box2{randi(10,1,1)},box1{randi(26,1,1)},box1{randi(26,1,1)},box2{randi(10,1,1)}];
plateAAAA=[box1{randi(26,1,1)},'',box2{randi(10,1,1)},box2{randi(10,1,1)},box1{randi(26,1,1)},box1{randi(26,1,1)},box2{randi(10,1,1)}];
plateB=[box1{randi(26,1,1)},'',box2{randi(10,1,1)},box2{randi(10,1,1)},box1{randi(26,1,1)},box1{randi(26,1,1)},box2{randi(10,1,1)}];
plateBB=[box1{randi(26,1,1)},'',box2{randi(10,1,1)},box2{randi(10,1,1)},box1{randi(26,1,1)},box1{randi(26,1,1)},box2{randi(10,1,1)}];
plateBBB=[box1{randi(26,1,1)},'',box2{randi(10,1,1)},box2{randi(10,1,1)},box1{randi(26,1,1)},box1{randi(26,1,1)},box2{randi(10,1,1)}];
plateBBBB=[box1{randi(26,1,1)},'',box2{randi(10,1,1)},box2{randi(10,1,1)},box1{randi(26,1,1)},box1{randi(26,1,1)},box2{randi(10,1,1)}];
if n==8
    while safe 
        for i=0:0.01:g
            x=x0+i;
            xx=xx0-i;
            yyy=yyy0+i;
            yyyy=yyyy0-i;
            a=a0+i;
            aa=aa0-i;
            bbb=bbb0+i;
            bbbb=bbbb0-i;
            if x(1)<=7.02 && x(1)>=6.97 && st==0
                if randi(round(1/p),1,1)==1
                    safe=false;               
                else
                    x0=x0-0.01;
                    xx0=xx0+0.01;
                    a0=a0-0.01;
                    aa0=aa0+0.01;
                end       
            elseif yyy(1)<=7.02 && yyy(1)>=6.97 && rd==0
                if randi(round(1/p),1,1)==1
                    safe=false;
                else
                    yyy0=yyy0-0.01;
                    yyyy0=yyyy0+0.01;
                    bbb0=bbb0-0.01;
                    bbbb0=bbbb0+0.01;
                end
            end
            if safe==false
                disp(plateAAA);
                disp(plateAAAA);
                disp(plateBBB);
                disp(plateBBBB);
                disp(plateA);
                disp(plateAA);
                disp(plateB);
                disp(plateBB);
                break
            end
            A=fill(x,y,'b');
            AA=fill(xx,yy,'c');
            AAA=fill(xxx,yyy,'m');
            AAAA=fill(xxxx,yyyy,'y');
            B=fill(a,b,'b');
            BB=fill(aa,bb,'c');
            BBB=fill(aaa,bbb,'m');
            BBBB=fill(aaaa,bbbb,'y');
            set(A,'xdata',x,'ydata',y)
            set(AA,'xdata',xx,'ydata',yy)
            set(AAA,'xdata',xxx,'ydata',yyy)
            set(AAAA,'xdata',xxxx,'ydata',yyyy)
            set(B,'xdata',a,'ydata',b)
            set(BB,'xdata',aa,'ydata',bb)
            set(BBB,'xdata',aaa,'ydata',bbb)
            set(BBBB,'xdata',aaaa,'ydata',bbbb)
            pause(0.01)
            if yyy(1)>=20
                disp('You win!')
                break
            end
        end
        x0=x;
        xx0=xx;
        yyy0=yyy;
        yyyy0=yyyy;
        a0=a;
        aa0=aa;
        bbb0=bbb;
        bbbb0=bbbb;
        circle(9.3,9.3,'y');
        circle(10.7+w,10.7+w,'y');     
        for i=0:0.01:o
            x=x0+i;
            xx=xx0-i;
            yyy=yyy0+i;
            yyyy=yyyy0-i;
            a=a0+i;
            aa=aa0-i;
            bbb=bbb0+i;
            bbbb=bbbb0-i;
            if x(1)<=7.02 && x(1)>=6.97 && st==0
                if randi(round(1/p),1,1)==1
                    safe=false;               
                else
                    x0=x0-0.01;
                    xx0=xx0+0.01;
                    a0=a0-0.01;
                    aa0=aa0+0.01;
                end       
            elseif yyy(1)<=7.02 && yyy(1)>=6.97 && rd==0
                if randi(round(1/p),1,1)==1
                    safe=false;
                else
                    yyy0=yyy0-0.01;
                    yyyy0=yyyy0+0.01;
                    bbb0=bbb0-0.01;
                    bbbb0=bbbb0+0.01;
                end
            end
            if safe==false
                disp(plateAAA);
                disp(plateAAAA);
                disp(plateBBB);
                disp(plateBBBB);
                disp(plateA);
                disp(plateAA);
                disp(plateB);
                disp(plateBB);
                break
            end
            A=fill(x,y,'b');
            AA=fill(xx,yy,'c');
            AAA=fill(xxx,yyy,'m');
            AAAA=fill(xxxx,yyyy,'y');
            B=fill(a,b,'b');
            BB=fill(aa,bb,'c');
            BBB=fill(aaa,bbb,'m');
            BBBB=fill(aaaa,bbbb,'y');
            set(A,'xdata',x,'ydata',y)
            set(AA,'xdata',xx,'ydata',yy)
            set(AAA,'xdata',xxx,'ydata',yyy)
            set(AAAA,'xdata',xxxx,'ydata',yyyy)
            set(B,'xdata',a,'ydata',b)
            set(BB,'xdata',aa,'ydata',bb)
            set(BBB,'xdata',aaa,'ydata',bbb)
            set(BBBB,'xdata',aaaa,'ydata',bbbb)
            pause(0.01)
            if yyy(1)>=20
                disp('You win!')
                break
            end
        end
        x0=x;
        xx0=xx;
        yyy0=yyy;
        yyyy0=yyyy;
        a0=a;
        aa0=aa;
        bbb0=bbb;
        bbbb0=bbbb;
        circle(9.3,9.3,'r');
        circle(10.7+w,10.7+w,'r');
        circle(10.7+w,9.3,'g');
        circle(9.3,10.7+w,'g');
        st=0;
        rd=1;     
        for i=0:0.01:g
            x=x0+i;
            xx=xx0-i;
            yyy=yyy0+i;
            yyyy=yyyy0-i;
            a=a0+i;
            aa=aa0-i;
            bbb=bbb0+i;
            bbbb=bbbb0-i;
            if x(1)<=7.02 && x(1)>=6.97 && st==0
                if randi(round(1/p),1,1)==1
                    safe=false;               
                else
                    x0=x0-0.01;
                    xx0=xx0+0.01;
                    a0=a0-0.01;
                    aa0=aa0+0.01;
                end       
            elseif yyy(1)<=7.02 && yyy(1)>=6.97 && rd==0
                if randi(round(1/p),1,1)==1
                    safe=false;
                else
                    yyy0=yyy0-0.01;
                    yyyy0=yyyy0+0.01;
                    bbb0=bbb0-0.01;
                    bbbb0=bbbb0+0.01;
                end
            end
            if safe==false
                disp(plateAAA);
                disp(plateAAAA);
                disp(plateBBB);
                disp(plateBBBB);
                disp(plateA);
                disp(plateAA);
                disp(plateB);
                disp(plateBB);
                break
            end
            A=fill(x,y,'b');
            AA=fill(xx,yy,'c');
            AAA=fill(xxx,yyy,'m');
            AAAA=fill(xxxx,yyyy,'y');
            B=fill(a,b,'b');
            BB=fill(aa,bb,'c');
            BBB=fill(aaa,bbb,'m');
            BBBB=fill(aaaa,bbbb,'y');
            set(A,'xdata',x,'ydata',y)
            set(AA,'xdata',xx,'ydata',yy)
            set(AAA,'xdata',xxx,'ydata',yyy)
            set(AAAA,'xdata',xxxx,'ydata',yyyy)
            set(B,'xdata',a,'ydata',b)
            set(BB,'xdata',aa,'ydata',bb)
            set(BBB,'xdata',aaa,'ydata',bbb)
            set(BBBB,'xdata',aaaa,'ydata',bbbb)
            pause(0.01)
            if yyy(1)>=20
                disp('You win!')
                break
            end
        end
        x0=x;
        xx0=xx;
        yyy0=yyy;
        yyyy0=yyyy;
        a0=a;
        aa0=aa;
        bbb0=bbb;
        bbbb0=bbbb;
        circle(10.7+w,9.3,'y');
        circle(9.3,10.7+w,'y');     
        for i=0:0.01:o
            x=x0+i;
            xx=xx0-i;
            yyy=yyy0+i;
            yyyy=yyyy0-i;
            a=a0+i;
            aa=aa0-i;
            bbb=bbb0+i;
            bbbb=bbbb0-i;
            if x(1)<=7.02 && x(1)>=6.97 && st==0
                if randi(round(1/p),1,1)==1
                    safe=false;               
                else
                    x0=x0-0.01;
                    xx0=xx0+0.01;
                    a0=a0-0.01;
                    aa0=aa0+0.01;
                end       
            elseif yyy(1)<=7.02 && yyy(1)>=6.97 && rd==0
                if randi(round(1/p),1,1)==1
                    safe=false;
                else
                    yyy0=yyy0-0.01;
                    yyyy0=yyyy0+0.01;
                    bbb0=bbb0-0.01;
                    bbbb0=bbbb0+0.01;
                end
            end
            if safe==false
                disp(plateAAA);
                disp(plateAAAA);
                disp(plateBBB);
                disp(plateBBBB);
                disp(plateA);
                disp(plateAA);
                disp(plateB);
                disp(plateBB);
                break
            end
            A=fill(x,y,'b');
            AA=fill(xx,yy,'c');
            AAA=fill(xxx,yyy,'m');
            AAAA=fill(xxxx,yyyy,'y');
            B=fill(a,b,'b');
            BB=fill(aa,bb,'c');
            BBB=fill(aaa,bbb,'m');
            BBBB=fill(aaaa,bbbb,'y');
            set(A,'xdata',x,'ydata',y)
            set(AA,'xdata',xx,'ydata',yy)
            set(AAA,'xdata',xxx,'ydata',yyy)
            set(AAAA,'xdata',xxxx,'ydata',yyyy)
            set(B,'xdata',a,'ydata',b)
            set(BB,'xdata',aa,'ydata',bb)
            set(BBB,'xdata',aaa,'ydata',bbb)
            set(BBBB,'xdata',aaaa,'ydata',bbbb)
            pause(0.01)
            if yyy(1)>=20
                disp('You win!')
                break
            end
        end
        x0=x;
        xx0=xx;
        yyy0=yyy;
        yyyy0=yyyy;
        a0=a;
        aa0=aa;
        bbb0=bbb;
        bbbb0=bbbb;
        circle(9.3,9.3,'g');
        circle(10.7+w,10.7+w,'g');
        circle(10.7+w,9.3,'r');
        circle(9.3,10.7+w,'r');
        st=1;
        rd=0;
        disp(plateA);
        disp(plateAA);
        disp(plateB);
        disp(plateBB);
        if yyy(1)>=20
            break
        end
    end
elseif n==9
    for i=0:0.01:3.5
        x=x0+i;
        xx=xx0-i;
        yyy=yyy0+i;
        yyyy=yyyy0-i;
        a=a0+i;
        aa=aa0-i;
        bbb=bbb0+i;
        bbbb=bbbb0-i;
        A=fill(x,y,'b');
        AA=fill(xx,yy,'c');
        AAA=fill(xxx,yyy,'m');
        AAAA=fill(xxxx,yyyy,'y');
        B=fill(a,b,'b');
        BB=fill(aa,bb,'c');
        BBB=fill(aaa,bbb,'m');
        BBBB=fill(aaaa,bbbb,'y');
        set(A,'xdata',x,'ydata',y)
        set(AA,'xdata',xx,'ydata',yy)
        set(AAA,'xdata',xxx,'ydata',yyy)
        set(AAAA,'xdata',xxxx,'ydata',yyyy)
        set(B,'xdata',a,'ydata',b)
        set(BB,'xdata',aa,'ydata',bb)
        set(BBB,'xdata',aaa,'ydata',bbb)
        set(BBBB,'xdata',aaaa,'ydata',bbbb)
        pause(0.01)
    end
    x0=x;
    xx0=xx;
    yyy0=yyy;
    yyyy0=yyyy;
    a0=a;
    aa0=aa;
    bbb0=bbb;
    bbbb0=bbbb;
    c0=[0 0 3 3];
    d=[10.2 9.8+w/2 9.8+w/2 10.2];
    plateC=[box1{randi(26,1,1)},'',box2{randi(10,1,1)},box2{randi(10,1,1)},box1{randi(26,1,1)},box1{randi(26,1,1)},box2{randi(10,1,1)}];
    while safe 
        for i=0:0.01:g
            x=x0+i;
            xx=xx0-i;
            yyy=yyy0+i;
            yyyy=yyyy0-i;
            a=a0+i;
            aa=aa0-i;
            bbb=bbb0+i;
            bbbb=bbbb0-i;
            c=c0+i;
            if x(1)<=7.02 && x(1)>=6.97 && st==0
                if randi(round(1/p),1,1)==1
                    safe=false;               
                else
                    x0=x0-0.01;
                    xx0=xx0+0.01;
                    a0=a0-0.01;
                    aa0=aa0+0.01;
                    c0=c0-0.01;
                end       
            elseif yyy(1)<=7.02 && yyy(1)>=6.97 && rd==0
                if randi(round(1/p),1,1)==1
                    safe=false;
                else
                    yyy0=yyy0-0.01;
                    yyyy0=yyyy0+0.01;
                    bbb0=bbb0-0.01;
                    bbbb0=bbbb0+0.01;
                end
            end
            if safe==false
                disp(plateAAA);
                disp(plateAAAA);
                disp(plateBBB);
                disp(plateBBBB);
                disp(plateA);
                disp(plateAA);
                disp(plateB);
                disp(plateBB);
                disp(plateC);
                break
            end
            A=fill(x,y,'b');
            AA=fill(xx,yy,'c');
            AAA=fill(xxx,yyy,'m');
            AAAA=fill(xxxx,yyyy,'y');
            B=fill(a,b,'b');
            BB=fill(aa,bb,'c');
            BBB=fill(aaa,bbb,'m');
            BBBB=fill(aaaa,bbbb,'y');
            C=fill(c,d,'b');
            set(A,'xdata',x,'ydata',y)
            set(AA,'xdata',xx,'ydata',yy)
            set(AAA,'xdata',xxx,'ydata',yyy)
            set(AAAA,'xdata',xxxx,'ydata',yyyy)
            set(B,'xdata',a,'ydata',b)
            set(BB,'xdata',aa,'ydata',bb)
            set(BBB,'xdata',aaa,'ydata',bbb)
            set(BBBB,'xdata',aaaa,'ydata',bbbb)
            set(C,'xdata',c,'ydata',d)
            pause(0.01)
            if yyy(1)>=20
                disp('You win!')
                break
            end
        end
        x0=x;
        xx0=xx;
        yyy0=yyy;
        yyyy0=yyyy;       
        a0=a;
        aa0=aa;
        bbb0=bbb;
        bbbb0=bbbb;
        c0=c;
        circle(9.3,9.3,'y');
        circle(10.7+w,10.7+w,'y');     
        for i=0:0.01:o
            x=x0+i;
            xx=xx0-i;
            yyy=yyy0+i;
            yyyy=yyyy0-i;
            a=a0+i;
            aa=aa0-i;
            bbb=bbb0+i;
            bbbb=bbbb0-i;
            c=c0+i;
            if x(1)<=7.02 && x(1)>=6.97 && st==0
                if randi(round(1/p),1,1)==1
                    safe=false;               
                else
                    x0=x0-0.01;
                    xx0=xx0+0.01;
                    a0=a0-0.01;
                    aa0=aa0+0.01;
                    c0=c0-0.01;
                end       
            elseif yyy(1)<=7.02 && yyy(1)>=6.97 && rd==0
                if randi(round(1/p),1,1)==1
                    safe=false;
                else
                    yyy0=yyy0-0.01;
                    yyyy0=yyyy0+0.01;
                    bbb0=bbb0-0.01;
                    bbbb0=bbbb0+0.01;
                end
            end
            if safe==false
                disp(plateAAA);
                disp(plateAAAA);
                disp(plateBBB);
                disp(plateBBBB);
                disp(plateA);
                disp(plateAA);
                disp(plateB);
                disp(plateBB);
                disp(plateC);
                break
            end
            A=fill(x,y,'b');
            AA=fill(xx,yy,'c');
            AAA=fill(xxx,yyy,'m');
            AAAA=fill(xxxx,yyyy,'y');
            B=fill(a,b,'b');
            BB=fill(aa,bb,'c');
            BBB=fill(aaa,bbb,'m');
            BBBB=fill(aaaa,bbbb,'y');
            C=fill(c,d,'b');
            set(A,'xdata',x,'ydata',y)
            set(AA,'xdata',xx,'ydata',yy)
            set(AAA,'xdata',xxx,'ydata',yyy)
            set(AAAA,'xdata',xxxx,'ydata',yyyy)
            set(B,'xdata',a,'ydata',b)
            set(BB,'xdata',aa,'ydata',bb)
            set(BBB,'xdata',aaa,'ydata',bbb)
            set(BBBB,'xdata',aaaa,'ydata',bbbb)
            set(C,'xdata',c,'ydata',d)
            pause(0.01)
            if yyy(1)>=20
                disp('You win!')
                break
            end
        end
        x0=x;
        xx0=xx;
        yyy0=yyy;
        yyyy0=yyyy;
        a0=a;
        aa0=aa;
        bbb0=bbb;
        bbbb0=bbbb;
        c0=c;
        circle(9.3,9.3,'r');
        circle(10.7+w,10.7+w,'r');
        circle(10.7+w,9.3,'g');
        circle(9.3,10.7+w,'g');
        st=0;
        rd=1;     
        for i=0:0.01:g
            x=x0+i;
            xx=xx0-i;
            yyy=yyy0+i;
            yyyy=yyyy0-i;
            a=a0+i;
            aa=aa0-i;
            bbb=bbb0+i;
            bbbb=bbbb0-i;
            c=c0+i;
            if x(1)<=7.02 && x(1)>=6.97 && st==0
                if randi(round(1/p),1,1)==1
                    safe=false;               
                else
                    x0=x0-0.01;
                    xx0=xx0+0.01;
                    a0=a0-0.01;
                    aa0=aa0+0.01;
                    c0=c0-0.01;
                end       
            elseif yyy(1)<=7.02 && yyy(1)>=6.97 && rd==0
                if randi(round(1/p),1,1)==1
                    safe=false;
                else
                    yyy0=yyy0-0.01;
                    yyyy0=yyyy0+0.01;
                    bbb0=bbb0-0.01;
                    bbbb0=bbbb0+0.01;
                end
            end
            if safe==false
                disp(plateAAA);
                disp(plateAAAA);
                disp(plateBBB);
                disp(plateBBBB);
                disp(plateA);
                disp(plateAA);
                disp(plateB);
                disp(plateBB);
                disp(plateC);
                break
            end
            A=fill(x,y,'b');
            AA=fill(xx,yy,'c');
            AAA=fill(xxx,yyy,'m');
            AAAA=fill(xxxx,yyyy,'y');
            B=fill(a,b,'b');
            BB=fill(aa,bb,'c');
            BBB=fill(aaa,bbb,'m');
            BBBB=fill(aaaa,bbbb,'y');
            C=fill(c,d,'b');
            set(A,'xdata',x,'ydata',y)
            set(AA,'xdata',xx,'ydata',yy)
            set(AAA,'xdata',xxx,'ydata',yyy)
            set(AAAA,'xdata',xxxx,'ydata',yyyy)
            set(B,'xdata',a,'ydata',b)
            set(BB,'xdata',aa,'ydata',bb)
            set(BBB,'xdata',aaa,'ydata',bbb)
            set(BBBB,'xdata',aaaa,'ydata',bbbb)
            set(C,'xdata',c,'ydata',d)
            pause(0.01)
            if yyy(1)>=20
                disp('You win!')
                break
            end
        end
        x0=x;
        xx0=xx;
        yyy0=yyy;
        yyyy0=yyyy;       
        a0=a;
        aa0=aa;
        bbb0=bbb;
        bbbb0=bbbb;
        c0=c;
        circle(9.3,9.3,'y');
        circle(10.7+w,10.7+w,'y'); 
        for i=0:0.01:o
            x=x0+i;
            xx=xx0-i;
            yyy=yyy0+i;
            yyyy=yyyy0-i;
            a=a0+i;
            aa=aa0-i;
            bbb=bbb0+i;
            bbbb=bbbb0-i;
            c=c0+i;
            if x(1)<=7.02 && x(1)>=6.97 && st==0
                if randi(round(1/p),1,1)==1
                    safe=false;               
                else
                    x0=x0-0.01;
                    xx0=xx0+0.01;
                    a0=a0-0.01;
                    aa0=aa0+0.01;
                    c0=c0-0.01;
                end       
            elseif yyy(1)<=7.02 && yyy(1)>=6.97 && rd==0
                if randi(round(1/p),1,1)==1
                    safe=false;
                else
                    yyy0=yyy0-0.01;
                    yyyy0=yyyy0+0.01;
                    bbb0=bbb0-0.01;
                    bbbb0=bbbb0+0.01;
                end
            end
            if safe==false
                disp(plateAAA);
                disp(plateAAAA);
                disp(plateBBB);
                disp(plateBBBB);
                disp(plateA);
                disp(plateAA);
                disp(plateB);
                disp(plateBB);
                disp(plateC);
                break
            end
            A=fill(x,y,'b');
            AA=fill(xx,yy,'c');
            AAA=fill(xxx,yyy,'m');
            AAAA=fill(xxxx,yyyy,'y');
            B=fill(a,b,'b');
            BB=fill(aa,bb,'c');
            BBB=fill(aaa,bbb,'m');
            BBBB=fill(aaaa,bbbb,'y');
            C=fill(c,d,'b');
            set(A,'xdata',x,'ydata',y)
            set(AA,'xdata',xx,'ydata',yy)
            set(AAA,'xdata',xxx,'ydata',yyy)
            set(AAAA,'xdata',xxxx,'ydata',yyyy)
            set(B,'xdata',a,'ydata',b)
            set(BB,'xdata',aa,'ydata',bb)
            set(BBB,'xdata',aaa,'ydata',bbb)
            set(BBBB,'xdata',aaaa,'ydata',bbbb)
            set(C,'xdata',c,'ydata',d)
            pause(0.01)
            if yyy(1)>=20
                disp('You win!')
                break
            end
        end
        x0=x;
        xx0=xx;
        yyy0=yyy;
        yyyy0=yyyy;
        a0=a;
        aa0=aa;
        bbb0=bbb;
        bbbb0=bbbb;
        c0=c;
        circle(9.3,9.3,'g');
        circle(10.7+w,10.7+w,'g');
        circle(10.7+w,9.3,'r');
        circle(9.3,10.7+w,'r');
        st=1;
        rd=0;
        disp(plateA);
        disp(plateAA);
        disp(plateB);
        disp(plateBB);
        disp(plateC);
        if yyy(1)>=20
            break
        end
    end
elseif n==10    
    for i=0:0.01:3.5
        x=x0+i;
        xx=xx0-i;
        yyy=yyy0+i;
        yyyy=yyyy0-i;
        a=a0+i;
        aa=aa0-i;
        bbb=bbb0+i;
        bbbb=bbbb0-i;
        A=fill(x,y,'b');
        AA=fill(xx,yy,'c');
        AAA=fill(xxx,yyy,'m');
        AAAA=fill(xxxx,yyyy,'y');
        B=fill(a,b,'b');
        BB=fill(aa,bb,'c');
        BBB=fill(aaa,bbb,'m');
        BBBB=fill(aaaa,bbbb,'y');
        set(A,'xdata',x,'ydata',y)
        set(AA,'xdata',xx,'ydata',yy)
        set(AAA,'xdata',xxx,'ydata',yyy)
        set(AAAA,'xdata',xxxx,'ydata',yyyy)
        set(B,'xdata',a,'ydata',b)
        set(BB,'xdata',aa,'ydata',bb)
        set(BBB,'xdata',aaa,'ydata',bbb)
        set(BBBB,'xdata',aaaa,'ydata',bbbb)
        pause(0.01)
    end
    x0=x;
    xx0=xx;
    yyy0=yyy;
    yyyy0=yyyy;
    a0=a;
    aa0=aa;
    bbb0=bbb;
    bbbb0=bbbb;
    c0=[0 0 3 3];
    d=[10.2 9.8+w/2 9.8+w/2 10.2];
    cc0=[17+w 17+w 20+w 20+w];
    dd=[10.2+w/2 9.8+w 9.8+w 10.2+w/2];
    plateC=[box1{randi(26,1,1)},'',box2{randi(10,1,1)},box2{randi(10,1,1)},box1{randi(26,1,1)},box1{randi(26,1,1)},box2{randi(10,1,1)}];
    plateCC=[box1{randi(26,1,1)},'',box2{randi(10,1,1)},box2{randi(10,1,1)},box1{randi(26,1,1)},box1{randi(26,1,1)},box2{randi(10,1,1)}];
    while safe 
        for i=0:0.01:g
            x=x0+i;
            xx=xx0-i;
            yyy=yyy0+i;
            yyyy=yyyy0-i;
            a=a0+i;
            aa=aa0-i;
            bbb=bbb0+i;
            bbbb=bbbb0-i;
            c=c0+i;
            cc=cc0-i;
            if x(1)<=7.02 && x(1)>=6.97 && st==0
                if randi(round(1/p),1,1)==1
                    safe=false;               
                else
                    x0=x0-0.01;
                    xx0=xx0+0.01;
                    a0=a0-0.01;
                    aa0=aa0+0.01;
                    c0=c0-0.01;
                    cc0=cc0+0.01;
                end       
            elseif yyy(1)<=7.02 && yyy(1)>=6.97 && rd==0
                if randi(round(1/p),1,1)==1
                    safe=false;
                else
                    yyy0=yyy0-0.01;
                    yyyy0=yyyy0+0.01;
                    bbb0=bbb0-0.01;
                    bbbb0=bbbb0+0.01;
                end
            end
            if safe==false
                disp(plateAAA);
                disp(plateAAAA);
                disp(plateBBB);
                disp(plateBBBB);
                disp(plateA);
                disp(plateAA);
                disp(plateB);
                disp(plateBB);
                disp(plateC);
                disp(plateCC);
                break
            end
            A=fill(x,y,'b');
            AA=fill(xx,yy,'c');
            AAA=fill(xxx,yyy,'m');
            AAAA=fill(xxxx,yyyy,'y');
            B=fill(a,b,'b');
            BB=fill(aa,bb,'c');
            BBB=fill(aaa,bbb,'m');
            BBBB=fill(aaaa,bbbb,'y');
            C=fill(c,d,'b');
            CC=fill(cc,dd,'c');
            set(A,'xdata',x,'ydata',y)
            set(AA,'xdata',xx,'ydata',yy)
            set(AAA,'xdata',xxx,'ydata',yyy)
            set(AAAA,'xdata',xxxx,'ydata',yyyy)
            set(B,'xdata',a,'ydata',b)
            set(BB,'xdata',aa,'ydata',bb)
            set(BBB,'xdata',aaa,'ydata',bbb)
            set(BBBB,'xdata',aaaa,'ydata',bbbb)
            set(C,'xdata',c,'ydata',d)
            set(CC,'xdata',cc,'ydata',dd)
            pause(0.01)
            if yyy(1)>=20
                disp('You win!')
                break
            end
        end
        x0=x;
        xx0=xx;
        yyy0=yyy;
        yyyy0=yyyy;       
        a0=a;
        aa0=aa;
        bbb0=bbb;
        bbbb0=bbbb;
        c0=c;
        cc0=cc;
        circle(9.3,9.3,'y');
        circle(10.7+w,10.7+w,'y');     
        for i=0:0.01:o
            x=x0+i;
            xx=xx0-i;
            yyy=yyy0+i;
            yyyy=yyyy0-i;
            a=a0+i;
            aa=aa0-i;
            bbb=bbb0+i;
            bbbb=bbbb0-i;
            c=c0+i;
            cc=cc0-i;
            if x(1)<=7.02 && x(1)>=6.97 && st==0
                if randi(round(1/p),1,1)==1
                    safe=false;               
                else
                    x0=x0-0.01;
                    xx0=xx0+0.01;
                    a0=a0-0.01;
                    aa0=aa0+0.01;
                    c0=c0-0.01;
                    cc0=cc0+0.01;
                end       
            elseif yyy(1)<=7.02 && yyy(1)>=6.97 && rd==0
                if randi(round(1/p),1,1)==1
                    safe=false;
                else
                    yyy0=yyy0-0.01;
                    yyyy0=yyyy0+0.01;
                    bbb0=bbb0-0.01;
                    bbbb0=bbbb0+0.01;
                end
            end
            if safe==false
                disp(plateAAA);
                disp(plateAAAA);
                disp(plateBBB);
                disp(plateBBBB);
                disp(plateA);
                disp(plateAA);
                disp(plateB);
                disp(plateBB);
                disp(plateC);
                disp(plateCC);
                break
            end
            A=fill(x,y,'b');
            AA=fill(xx,yy,'c');
            AAA=fill(xxx,yyy,'m');
            AAAA=fill(xxxx,yyyy,'y');
            B=fill(a,b,'b');
            BB=fill(aa,bb,'c');
            BBB=fill(aaa,bbb,'m');
            BBBB=fill(aaaa,bbbb,'y');
            C=fill(c,d,'b');
            CC=fill(cc,dd,'c');
            set(A,'xdata',x,'ydata',y)
            set(AA,'xdata',xx,'ydata',yy)
            set(AAA,'xdata',xxx,'ydata',yyy)
            set(AAAA,'xdata',xxxx,'ydata',yyyy)
            set(B,'xdata',a,'ydata',b)
            set(BB,'xdata',aa,'ydata',bb)
            set(BBB,'xdata',aaa,'ydata',bbb)
            set(BBBB,'xdata',aaaa,'ydata',bbbb)
            set(C,'xdata',c,'ydata',d)
            set(CC,'xdata',cc,'ydata',dd)
            pause(0.01)
            if yyy(1)>=20
                disp('You win!')
                break
            end
        end
        x0=x;
        xx0=xx;
        yyy0=yyy;
        yyyy0=yyyy;       
        a0=a;
        aa0=aa;
        bbb0=bbb;
        bbbb0=bbbb;
        c0=c;
        cc0=cc;
        circle(9.3,9.3,'r');
        circle(10.7+w,10.7+w,'r');
        circle(10.7+w,9.3,'g');
        circle(9.3,10.7+w,'g');
        st=0;
        rd=1;     
        for i=0:0.01:g
            x=x0+i;
            xx=xx0-i;
            yyy=yyy0+i;
            yyyy=yyyy0-i;
            a=a0+i;
            aa=aa0-i;
            bbb=bbb0+i;
            bbbb=bbbb0-i;
            c=c0+i;
            cc=cc0-i;
            if x(1)<=7.02 && x(1)>=6.97 && st==0
                if randi(round(1/p),1,1)==1
                    safe=false;               
                else
                    x0=x0-0.01;
                    xx0=xx0+0.01;
                    a0=a0-0.01;
                    aa0=aa0+0.01;
                    c0=c0-0.01;
                    cc0=cc0+0.01;
                end       
            elseif yyy(1)<=7.02 && yyy(1)>=6.97 && rd==0
                if randi(round(1/p),1,1)==1
                    safe=false;
                else
                    yyy0=yyy0-0.01;
                    yyyy0=yyyy0+0.01;
                    bbb0=bbb0-0.01;
                    bbbb0=bbbb0+0.01;
                end
            end
            if safe==false
                disp(plateAAA);
                disp(plateAAAA);
                disp(plateBBB);
                disp(plateBBBB);
                disp(plateA);
                disp(plateAA);
                disp(plateB);
                disp(plateBB);
                disp(plateC);
                disp(plateCC);
                break
            end
            A=fill(x,y,'b');
            AA=fill(xx,yy,'c');
            AAA=fill(xxx,yyy,'m');
            AAAA=fill(xxxx,yyyy,'y');
            B=fill(a,b,'b');
            BB=fill(aa,bb,'c');
            BBB=fill(aaa,bbb,'m');
            BBBB=fill(aaaa,bbbb,'y');
            C=fill(c,d,'b');
            CC=fill(cc,dd,'c');
            set(A,'xdata',x,'ydata',y)
            set(AA,'xdata',xx,'ydata',yy)
            set(AAA,'xdata',xxx,'ydata',yyy)
            set(AAAA,'xdata',xxxx,'ydata',yyyy)
            set(B,'xdata',a,'ydata',b)
            set(BB,'xdata',aa,'ydata',bb)
            set(BBB,'xdata',aaa,'ydata',bbb)
            set(BBBB,'xdata',aaaa,'ydata',bbbb)
            set(C,'xdata',c,'ydata',d)
            set(CC,'xdata',cc,'ydata',dd)
            pause(0.01)
            if yyy(1)>=20
                disp('You win!')
                break
            end
        end
        x0=x;
        xx0=xx;
        yyy0=yyy;
        yyyy0=yyyy;       
        a0=a;
        aa0=aa;
        bbb0=bbb;
        bbbb0=bbbb;
        c0=c;
        cc0=cc;
        circle(10.7+w,9.3,'y');
        circle(9.3,10.7+w,'y');
        for i=0:0.01:o
            x=x0+i;
            xx=xx0-i;
            yyy=yyy0+i;
            yyyy=yyyy0-i;
            a=a0+i;
            aa=aa0-i;
            bbb=bbb0+i;
            bbbb=bbbb0-i;
            c=c0+i;
            cc=cc0-i;
            if x(1)<=7.02 && x(1)>=6.97 && st==0
                if randi(round(1/p),1,1)==1
                    safe=false;               
                else
                    x0=x0-0.01;
                    xx0=xx0+0.01;
                    a0=a0-0.01;
                    aa0=aa0+0.01;
                    c0=c0-0.01;
                    cc0=cc0+0.01;
                end       
            elseif yyy(1)<=7.02 && yyy(1)>=6.97 && rd==0
                if randi(round(1/p),1,1)==1
                    safe=false;
                else
                    yyy0=yyy0-0.01;
                    yyyy0=yyyy0+0.01;
                    bbb0=bbb0-0.01;
                    bbbb0=bbbb0+0.01;
                end
            end
            if safe==false
                disp(plateAAA);
                disp(plateAAAA);
                disp(plateBBB);
                disp(plateBBBB);
                disp(plateA);
                disp(plateAA);
                disp(plateB);
                disp(plateBB);
                disp(plateC);
                disp(plateCC);
                break
            end
            A=fill(x,y,'b');
            AA=fill(xx,yy,'c');
            AAA=fill(xxx,yyy,'m');
            AAAA=fill(xxxx,yyyy,'y');
            B=fill(a,b,'b');
            BB=fill(aa,bb,'c');
            BBB=fill(aaa,bbb,'m');
            BBBB=fill(aaaa,bbbb,'y');
            C=fill(c,d,'b');
            CC=fill(cc,dd,'c');
            set(A,'xdata',x,'ydata',y)
            set(AA,'xdata',xx,'ydata',yy)
            set(AAA,'xdata',xxx,'ydata',yyy)
            set(AAAA,'xdata',xxxx,'ydata',yyyy)
            set(B,'xdata',a,'ydata',b)
            set(BB,'xdata',aa,'ydata',bb)
            set(BBB,'xdata',aaa,'ydata',bbb)
            set(BBBB,'xdata',aaaa,'ydata',bbbb)
            set(C,'xdata',c,'ydata',d)
            set(CC,'xdata',cc,'ydata',dd)
            pause(0.01)
            if yyy(1)>=20
                disp('You win!')
                break
            end
        end
        x0=x;
        xx0=xx;
        yyy0=yyy;
        yyyy0=yyyy;       
        a0=a;
        aa0=aa;
        bbb0=bbb;
        bbbb0=bbbb;
        c0=c;
        cc0=cc;
        circle(9.3,9.3,'g');
        circle(10.7+w,10.7+w,'g');
        circle(10.7+w,9.3,'r');
        circle(9.3,10.7+w,'r');
        st=1;
        rd=0;
        disp(plateA);
        disp(plateAA);
        disp(plateB);
        disp(plateBB);
        disp(plateC);
        disp(plateCC);
        if yyy(1)>=20
            break
        end
    end
elseif n==11
    for i=0:0.01:3.5
        x=x0+i;
        xx=xx0-i;
        yyy=yyy0+i;
        yyyy=yyyy0-i;
        a=a0+i;
        aa=aa0-i;
        bbb=bbb0+i;
        bbbb=bbbb0-i;
        A=fill(x,y,'b');
        AA=fill(xx,yy,'c');
        AAA=fill(xxx,yyy,'m');
        AAAA=fill(xxxx,yyyy,'y');
        B=fill(a,b,'b');
        BB=fill(aa,bb,'c');
        BBB=fill(aaa,bbb,'m');
        BBBB=fill(aaaa,bbbb,'y');
        set(A,'xdata',x,'ydata',y)
        set(AA,'xdata',xx,'ydata',yy)
        set(AAA,'xdata',xxx,'ydata',yyy)
        set(AAAA,'xdata',xxxx,'ydata',yyyy)
        set(B,'xdata',a,'ydata',b)
        set(BB,'xdata',aa,'ydata',bb)
        set(BBB,'xdata',aaa,'ydata',bbb)
        set(BBBB,'xdata',aaaa,'ydata',bbbb)
        pause(0.01)
    end
    x0=x;
    xx0=xx;
    yyy0=yyy;
    yyyy0=yyyy;
    a0=a;
    aa0=aa;
    bbb0=bbb;
    bbbb0=bbbb;
    c0=[0 0 3 3];
    d=[10.2 9.8+w/2 9.8+w/2 10.2];
    cc0=[17+w 17+w 20+w 20+w];
    dd=[10.2+w/2 9.8+w 9.8+w 10.2+w/2];
    ccc=[10.2+w/2 9.8+w 9.8+w 10.2+w/2];
    ddd0=[0 0 3 3];
    plateC=[box1{randi(26,1,1)},'',box2{randi(10,1,1)},box2{randi(10,1,1)},box1{randi(26,1,1)},box1{randi(26,1,1)},box2{randi(10,1,1)}];
    plateCC=[box1{randi(26,1,1)},'',box2{randi(10,1,1)},box2{randi(10,1,1)},box1{randi(26,1,1)},box1{randi(26,1,1)},box2{randi(10,1,1)}];
    plateCCC=[box1{randi(26,1,1)},'',box2{randi(10,1,1)},box2{randi(10,1,1)},box1{randi(26,1,1)},box1{randi(26,1,1)},box2{randi(10,1,1)}];
    while safe 
        for i=0:0.01:g
            x=x0+i;
            xx=xx0-i;
            yyy=yyy0+i;
            yyyy=yyyy0-i;
            a=a0+i;
            aa=aa0-i;
            bbb=bbb0+i;
            bbbb=bbbb0-i;
            c=c0+i;
            cc=cc0-i;
            ddd=ddd0+i;
            if x(1)<=7.02 && x(1)>=6.97 && st==0
                if randi(round(1/p),1,1)==1
                    safe=false;               
                else
                    x0=x0-0.01;
                    xx0=xx0+0.01;
                    a0=a0-0.01;
                    aa0=aa0+0.01;
                    c0=c0-0.01;
                    cc0=cc0+0.01;                  
                end       
            elseif yyy(1)<=7.02 && yyy(1)>=6.97 && rd==0
                if randi(round(1/p),1,1)==1
                    safe=false;
                else
                    yyy0=yyy0-0.01;
                    yyyy0=yyyy0+0.01;
                    bbb0=bbb0-0.01;
                    bbbb0=bbbb0+0.01;
                    ddd0=ddd0-0.01;
                end
            end
            if safe==false
                disp(plateAAA);
                disp(plateAAAA);
                disp(plateBBB);
                disp(plateBBBB);
                disp(plateA);
                disp(plateAA);
                disp(plateB);
                disp(plateBB);
                disp(plateC);
                disp(plateCC);
                disp(plateCCC);
                break
            end
            A=fill(x,y,'b');
            AA=fill(xx,yy,'c');
            AAA=fill(xxx,yyy,'m');
            AAAA=fill(xxxx,yyyy,'y');
            B=fill(a,b,'b');
            BB=fill(aa,bb,'c');
            BBB=fill(aaa,bbb,'m');
            BBBB=fill(aaaa,bbbb,'y');
            C=fill(c,d,'b');
            CC=fill(cc,dd,'c');
            CCC=fill(ccc,ddd,'m');
            set(A,'xdata',x,'ydata',y)
            set(AA,'xdata',xx,'ydata',yy)
            set(AAA,'xdata',xxx,'ydata',yyy)
            set(AAAA,'xdata',xxxx,'ydata',yyyy)
            set(B,'xdata',a,'ydata',b)
            set(BB,'xdata',aa,'ydata',bb)
            set(BBB,'xdata',aaa,'ydata',bbb)
            set(BBBB,'xdata',aaaa,'ydata',bbbb)
            set(C,'xdata',c,'ydata',d)
            set(CC,'xdata',cc,'ydata',dd)
            set(CCC,'xdata',ccc,'ydata',ddd)
            pause(0.01)
            if yyy(1)>=20
                disp('You win!')
                break
            end
        end
        x0=x;
        xx0=xx;
        yyy0=yyy;
        yyyy0=yyyy;       
        a0=a;
        aa0=aa;
        bbb0=bbb;
        bbbb0=bbbb;
        c0=c;
        cc0=cc;
        ddd0=ddd;
        circle(9.3,9.3,'y');
        circle(10.7+w,10.7+w,'y');     
        for i=0:0.01:o
            x=x0+i;
            xx=xx0-i;
            yyy=yyy0+i;
            yyyy=yyyy0-i;
            a=a0+i;
            aa=aa0-i;
            bbb=bbb0+i;
            bbbb=bbbb0-i;
            c=c0+i;
            cc=cc0-1;
            ddd=ddd0+i;
            if x(1)<=7.02 && x(1)>=6.97 && st==0
                if randi(round(1/p),1,1)==1
                    safe=false;               
                else
                    x0=x0-0.01;
                    xx0=xx0+0.01;
                    a0=a0-0.01;
                    aa0=aa0+0.01;
                    c0=c0-0.01;
                    cc0=cc0+0.01;                  
                end       
            elseif yyy(1)<=7.02 && yyy(1)>=6.97 && rd==0
                if randi(round(1/p),1,1)==1
                    safe=false;
                else
                    yyy0=yyy0-0.01;
                    yyyy0=yyyy0+0.01;
                    bbb0=bbb0-0.01;
                    bbbb0=bbbb0+0.01;
                    ddd0=ddd0-0.01;
                end
            end
            if safe==false
                disp(plateAAA);
                disp(plateAAAA);
                disp(plateBBB);
                disp(plateBBBB);
                disp(plateA);
                disp(plateAA);
                disp(plateB);
                disp(plateBB);
                disp(plateC);
                disp(plateCC);
                disp(plateCCC);
                break
            end
            A=fill(x,y,'b');
            AA=fill(xx,yy,'c');
            AAA=fill(xxx,yyy,'m');
            AAAA=fill(xxxx,yyyy,'y');
            B=fill(a,b,'b');
            BB=fill(aa,bb,'c');
            BBB=fill(aaa,bbb,'m');
            BBBB=fill(aaaa,bbbb,'y');
            C=fill(c,d,'b');
            CC=fill(cc,dd,'c');
            CCC=fill(ccc,ddd,'m');
            set(A,'xdata',x,'ydata',y)
            set(AA,'xdata',xx,'ydata',yy)
            set(AAA,'xdata',xxx,'ydata',yyy)
            set(AAAA,'xdata',xxxx,'ydata',yyyy)
            set(B,'xdata',a,'ydata',b)
            set(BB,'xdata',aa,'ydata',bb)
            set(BBB,'xdata',aaa,'ydata',bbb)
            set(BBBB,'xdata',aaaa,'ydata',bbbb)
            set(C,'xdata',c,'ydata',d)
            set(CC,'xdata',cc,'ydata',dd)
            set(CCC,'xdata',ccc,'ydata',ddd)
            pause(0.01)
            if yyy(1)>=20
                disp('You win!')
                break
            end
        end
        x0=x;
        xx0=xx;
        yyy0=yyy;
        yyyy0=yyyy;       
        a0=a;
        aa0=aa;
        bbb0=bbb;
        bbbb0=bbbb;
        c0=c;
        cc0=cc;
        ddd0=ddd;
        circle(9.3,9.3,'r');
        circle(10.7+w,10.7+w,'r');
        circle(10.7+w,9.3,'g');
        circle(9.3,10.7+w,'g');
        st=0;
        rd=1;     
        for i=0:0.01:g
            x=x0+i;
            xx=xx0-i;
            yyy=yyy0+i;
            yyyy=yyyy0-i;
            a=a0+i;
            aa=aa0-i;
            bbb=bbb0+i;
            bbbb=bbbb0-i;
            c=c0+i;
            cc=cc0-i;
            ddd=ddd0+i;
            if x(1)<=7.02 && x(1)>=6.97 && st==0
                if randi(round(1/p),1,1)==1
                    safe=false;               
                else
                    x0=x0-0.01;
                    xx0=xx0+0.01;
                    a0=a0-0.01;
                    aa0=aa0+0.01;
                    c0=c0-0.01;
                    cc0=cc0+0.01;                  
                end       
            elseif yyy(1)<=7.02 && yyy(1)>=6.97 && rd==0
                if randi(round(1/p),1,1)==1
                    safe=false;
                else
                    yyy0=yyy0-0.01;
                    yyyy0=yyyy0+0.01;
                    bbb0=bbb0-0.01;
                    bbbb0=bbbb0+0.01;
                    ddd0=ddd0-0.01;
                end
            end
            if safe==false
                disp(plateAAA);
                disp(plateAAAA);
                disp(plateBBB);
                disp(plateBBBB);
                disp(plateA);
                disp(plateAA);
                disp(plateB);
                disp(plateBB);
                disp(plateC);
                disp(plateCC);
                disp(plateCCC);
                break
            end
            A=fill(x,y,'b');
            AA=fill(xx,yy,'c');
            AAA=fill(xxx,yyy,'m');
            AAAA=fill(xxxx,yyyy,'y');
            B=fill(a,b,'b');
            BB=fill(aa,bb,'c');
            BBB=fill(aaa,bbb,'m');
            BBBB=fill(aaaa,bbbb,'y');
            C=fill(c,d,'b');
            CC=fill(cc,dd,'c');
            CCC=fill(ccc,ddd,'m');
            set(A,'xdata',x,'ydata',y)
            set(AA,'xdata',xx,'ydata',yy)
            set(AAA,'xdata',xxx,'ydata',yyy)
            set(AAAA,'xdata',xxxx,'ydata',yyyy)
            set(B,'xdata',a,'ydata',b)
            set(BB,'xdata',aa,'ydata',bb)
            set(BBB,'xdata',aaa,'ydata',bbb)
            set(BBBB,'xdata',aaaa,'ydata',bbbb)
            set(C,'xdata',c,'ydata',d)
            set(CC,'xdata',cc,'ydata',dd)
            set(CCC,'xdata',ccc,'ydata',ddd)
            pause(0.01)
            if yyy(1)>=20
                disp('You win!')
                break
            end
        end
        x0=x;
        xx0=xx;
        yyy0=yyy;
        yyyy0=yyyy;       
        a0=a;
        aa0=aa;
        bbb0=bbb;
        bbbb0=bbbb;
        c0=c;
        cc0=cc;
        ddd0=ddd;
        circle(10.7+w,9.3,'y');
        circle(9.3,10.7+w,'y');
        for i=0:0.01:o
            x=x0+i;
            xx=xx0-i;
            yyy=yyy0+i;
            yyyy=yyyy0-i;
            a=a0+i;
            aa=aa0-i;
            bbb=bbb0+i;
            bbbb=bbbb0-i;
            c=c0+i;
            cc=cc0-i;
            ddd=ddd0+i;
            if x(1)<=7.02 && x(1)>=6.97 && st==0
                if randi(round(1/p),1,1)==1
                    safe=false;               
                else
                    x0=x0-0.01;
                    xx0=xx0+0.01;
                    a0=a0-0.01;
                    aa0=aa0+0.01;
                    c0=c0-0.01;
                    cc0=cc0+0.01;                  
                end       
            elseif yyy(1)<=7.02 && yyy(1)>=6.97 && rd==0
                if randi(round(1/p),1,1)==1
                    safe=false;
                else
                    yyy0=yyy0-0.01;
                    yyyy0=yyyy0+0.01;
                    bbb0=bbb0-0.01;
                    bbbb0=bbbb0+0.01;
                    ddd0=ddd0-0.01;
                end
            end
            if safe==false
                disp(plateAAA);
                disp(plateAAAA);
                disp(plateBBB);
                disp(plateBBBB);
                disp(plateA);
                disp(plateAA);
                disp(plateB);
                disp(plateBB);
                disp(plateC);
                disp(plateCC);
                disp(plateCCC);
                break
            end
            A=fill(x,y,'b');
            AA=fill(xx,yy,'c');
            AAA=fill(xxx,yyy,'m');
            AAAA=fill(xxxx,yyyy,'y');
            B=fill(a,b,'b');
            BB=fill(aa,bb,'c');
            BBB=fill(aaa,bbb,'m');
            BBBB=fill(aaaa,bbbb,'y');
            C=fill(c,d,'b');
            CC=fill(cc,dd,'c');
            CCC=fill(ccc,ddd,'m');
            set(A,'xdata',x,'ydata',y)
            set(AA,'xdata',xx,'ydata',yy)
            set(AAA,'xdata',xxx,'ydata',yyy)
            set(AAAA,'xdata',xxxx,'ydata',yyyy)
            set(B,'xdata',a,'ydata',b)
            set(BB,'xdata',aa,'ydata',bb)
            set(BBB,'xdata',aaa,'ydata',bbb)
            set(BBBB,'xdata',aaaa,'ydata',bbbb)
            set(C,'xdata',c,'ydata',d)
            set(CC,'xdata',cc,'ydata',dd)
            set(CCC,'xdata',ccc,'ydata',ddd)
            pause(0.01)
            if yyy(1)>=20
                disp('You win!')
                break
            end
        end
        x0=x;
        xx0=xx;
        yyy0=yyy;
        yyyy0=yyyy;       
        a0=a;
        aa0=aa;
        bbb0=bbb;
        bbbb0=bbbb;
        c0=c;
        cc0=cc;
        ddd0=ddd;
        circle(9.3,9.3,'g');
        circle(10.7+w,10.7+w,'g');
        circle(10.7+w,9.3,'r');
        circle(9.3,10.7+w,'r');
        st=1;
        rd=0;
        disp(plateA);
        disp(plateAA);
        disp(plateB);
        disp(plateBB);
        disp(plateC);
        disp(plateCC);
        if yyy(1)>=20
            break
        end
    end
else
    for i=0:0.01:3.5
        x=x0+i;
        xx=xx0-i;
        yyy=yyy0+i;
        yyyy=yyyy0-i;
        a=a0+i;
        aa=aa0-i;
        bbb=bbb0+i;
        bbbb=bbbb0-i;
        A=fill(x,y,'b');
        AA=fill(xx,yy,'c');
        AAA=fill(xxx,yyy,'m');
        AAAA=fill(xxxx,yyyy,'y');
        B=fill(a,b,'b');
        BB=fill(aa,bb,'c');
        BBB=fill(aaa,bbb,'m');
        BBBB=fill(aaaa,bbbb,'y');
        set(A,'xdata',x,'ydata',y)
        set(AA,'xdata',xx,'ydata',yy)
        set(AAA,'xdata',xxx,'ydata',yyy)
        set(AAAA,'xdata',xxxx,'ydata',yyyy)
        set(B,'xdata',a,'ydata',b)
        set(BB,'xdata',aa,'ydata',bb)
        set(BBB,'xdata',aaa,'ydata',bbb)
        set(BBBB,'xdata',aaaa,'ydata',bbbb)
        pause(0.01)
    end
    x0=x;
    xx0=xx;
    yyy0=yyy;
    yyyy0=yyyy;
    a0=a;
    aa0=aa;
    bbb0=bbb;
    bbbb0=bbbb;
    c0=[0 0 3 3];
    d=[10.2 9.8+w/2 9.8+w/2 10.2];
    cc0=[17+w 17+w 20+w 20+w];
    dd=[10.2+w/2 9.8+w 9.8+w 10.2+w/2];
    ccc=[10.2+w/2 9.8+w 9.8+w 10.2+w/2];
    ddd0=[0 0 3 3];   
    cccc=[10.2 9.8+w/2 9.8+w/2 10.2];
    dddd0=[17+w 17+w 20+w 20+w];
    plateC=[box1{randi(26,1,1)},'',box2{randi(10,1,1)},box2{randi(10,1,1)},box1{randi(26,1,1)},box1{randi(26,1,1)},box2{randi(10,1,1)}];
    plateCC=[box1{randi(26,1,1)},'',box2{randi(10,1,1)},box2{randi(10,1,1)},box1{randi(26,1,1)},box1{randi(26,1,1)},box2{randi(10,1,1)}];
    plateCCC=[box1{randi(26,1,1)},'',box2{randi(10,1,1)},box2{randi(10,1,1)},box1{randi(26,1,1)},box1{randi(26,1,1)},box2{randi(10,1,1)}];
    plateCCCC=[box1{randi(26,1,1)},'',box2{randi(10,1,1)},box2{randi(10,1,1)},box1{randi(26,1,1)},box1{randi(26,1,1)},box2{randi(10,1,1)}];
    while safe 
        for i=0:0.01:g
            x=x0+i;
            xx=xx0-i;
            yyy=yyy0+i;
            yyyy=yyyy0-i;
            a=a0+i;
            aa=aa0-i;
            bbb=bbb0+i;
            bbbb=bbbb0-i;
            c=c0+i;
            cc=cc0-i;
            ddd=ddd0+i;
            dddd=dddd0-i;
            if x(1)<=7.02 && x(1)>=6.97 && st==0
                if randi(round(1/p),1,1)==1
                    safe=false;               
                else
                    x0=x0-0.01;
                    xx0=xx0+0.01;
                    a0=a0-0.01;
                    aa0=aa0+0.01;
                    c0=c0-0.01;
                    cc0=cc0+0.01;                  
                end       
            elseif yyy(1)<=7.02 && yyy(1)>=6.97 && rd==0
                if randi(round(1/p),1,1)==1
                    safe=false;
                else
                    yyy0=yyy0-0.01;
                    yyyy0=yyyy0+0.01;
                    bbb0=bbb0-0.01;
                    bbbb0=bbbb0+0.01;
                    ddd0=ddd0-0.01;
                    dddd0=dddd0+0.01;
                end
            end
            if safe==false
                disp(plateAAA);
                disp(plateAAAA);
                disp(plateBBB);
                disp(plateBBBB);
                disp(plateA);
                disp(plateAA);
                disp(plateB);
                disp(plateBB);
                disp(plateC);
                disp(plateCC);
                disp(plateCCC);
                disp(plateCCCC);
                break
            end
            A=fill(x,y,'b');
            AA=fill(xx,yy,'c');
            AAA=fill(xxx,yyy,'m');
            AAAA=fill(xxxx,yyyy,'y');
            B=fill(a,b,'b');
            BB=fill(aa,bb,'c');
            BBB=fill(aaa,bbb,'m');
            BBBB=fill(aaaa,bbbb,'y');
            C=fill(c,d,'b');
            CC=fill(cc,dd,'c');
            CCC=fill(ccc,ddd,'m');
            CCCC=fill(cccc,dddd,'y');
            set(A,'xdata',x,'ydata',y)
            set(AA,'xdata',xx,'ydata',yy)
            set(AAA,'xdata',xxx,'ydata',yyy)
            set(AAAA,'xdata',xxxx,'ydata',yyyy)
            set(B,'xdata',a,'ydata',b)
            set(BB,'xdata',aa,'ydata',bb)
            set(BBB,'xdata',aaa,'ydata',bbb)
            set(BBBB,'xdata',aaaa,'ydata',bbbb)
            set(C,'xdata',c,'ydata',d)
            set(CC,'xdata',cc,'ydata',dd)
            set(CCC,'xdata',ccc,'ydata',ddd)
            set(CCCC,'xdata',cccc,'ydata',dddd)
            pause(0.01)
            if yyy(1)>=20
                disp('You win!')
                break
            end
        end
        x0=x;
        xx0=xx;
        yyy0=yyy;
        yyyy0=yyyy;       
        a0=a;
        aa0=aa;
        bbb0=bbb;
        bbbb0=bbbb;
        c0=c;
        cc0=cc;
        ddd0=ddd;
        dddd0=dddd;
        circle(9.3,9.3,'y');
        circle(10.7+w,10.7+w,'y');     
        for i=0:0.01:o
            x=x0+i;
            xx=xx0-i;
            yyy=yyy0+i;
            yyyy=yyyy0-i;
            a=a0+i;
            aa=aa0-i;
            bbb=bbb0+i;
            bbbb=bbbb0-i;
            c=c0+i;
            cc=cc0-i;
            ddd=ddd0+i;
            dddd=dddd0-i;
            if x(1)<=7.02 && x(1)>=6.97 && st==0
                if randi(round(1/p),1,1)==1
                    safe=false;               
                else
                    x0=x0-0.01;
                    xx0=xx0+0.01;
                    a0=a0-0.01;
                    aa0=aa0+0.01;
                    c0=c0-0.01;
                    cc0=cc0+0.01;                  
                end       
            elseif yyy(1)<=7.02 && yyy(1)>=6.97 && rd==0
                if randi(round(1/p),1,1)==1
                    safe=false;
                else
                    yyy0=yyy0-0.01;
                    yyyy0=yyyy0+0.01;
                    bbb0=bbb0-0.01;
                    bbbb0=bbbb0+0.01;
                    ddd0=ddd0-0.01;
                    dddd0=dddd0+0.01;
                end
            end
            if safe==false
                disp(plateAAA);
                disp(plateAAAA);
                disp(plateBBB);
                disp(plateBBBB);
                disp(plateA);
                disp(plateAA);
                disp(plateB);
                disp(plateBB);
                disp(plateC);
                disp(plateCC);
                disp(plateCCC);
                disp(plateCCCC);
                break
            end
            A=fill(x,y,'b');
            AA=fill(xx,yy,'c');
            AAA=fill(xxx,yyy,'m');
            AAAA=fill(xxxx,yyyy,'y');
            B=fill(a,b,'b');
            BB=fill(aa,bb,'c');
            BBB=fill(aaa,bbb,'m');
            BBBB=fill(aaaa,bbbb,'y');
            C=fill(c,d,'b');
            CC=fill(cc,dd,'c');
            CCC=fill(ccc,ddd,'m');
            CCCC=fill(cccc,dddd,'y');
            set(A,'xdata',x,'ydata',y)
            set(AA,'xdata',xx,'ydata',yy)
            set(AAA,'xdata',xxx,'ydata',yyy)
            set(AAAA,'xdata',xxxx,'ydata',yyyy)
            set(B,'xdata',a,'ydata',b)
            set(BB,'xdata',aa,'ydata',bb)
            set(BBB,'xdata',aaa,'ydata',bbb)
            set(BBBB,'xdata',aaaa,'ydata',bbbb)
            set(C,'xdata',c,'ydata',d)
            set(CC,'xdata',cc,'ydata',dd)
            set(CCC,'xdata',ccc,'ydata',ddd)
            set(CCCC,'xdata',cccc,'ydata',dddd)
            pause(0.01)
            if yyy(1)>=20
                disp('You win!')
                safe=false;
                break
            end
        end
        x0=x;
        xx0=xx;
        yyy0=yyy;
        yyyy0=yyyy;       
        a0=a;
        aa0=aa;
        bbb0=bbb;
        bbbb0=bbbb;
        c0=c;
        cc0=cc;
        ddd0=ddd;
        dddd0=dddd;
        circle(9.3,9.3,'r');
        circle(10.7+w,10.7+w,'r');
        circle(10.7+w,9.3,'g');
        circle(9.3,10.7+w,'g');
        st=0;
        rd=1;     
        for i=0:0.01:g
            x=x0+i;
            xx=xx0-i;
            yyy=yyy0+i;
            yyyy=yyyy0-i;
            a=a0+i;
            aa=aa0-i;
            bbb=bbb0+i;
            bbbb=bbbb0-i;
            c=c0+i;
            cc=cc0-i;
            ddd=ddd0+i;
            dddd=dddd0-i;
            if x(1)<=7.02 && x(1)>=6.97 && st==0
                if randi(round(1/p),1,1)==1
                    safe=false;               
                else
                    x0=x0-0.01;
                    xx0=xx0+0.01;
                    a0=a0-0.01;
                    aa0=aa0+0.01;
                    c0=c0-0.01;
                    cc0=cc0+0.01;                  
                end       
            elseif yyy(1)<=7.02 && yyy(1)>=6.97 && rd==0
                if randi(round(1/p),1,1)==1
                    safe=false;
                else
                    yyy0=yyy0-0.01;
                    yyyy0=yyyy0+0.01;
                    bbb0=bbb0-0.01;
                    bbbb0=bbbb0+0.01;
                    ddd0=ddd0-0.01;
                    dddd0=dddd0+0.01;
                end
            end
            if safe==false
                disp(plateAAA);
                disp(plateAAAA);
                disp(plateBBB);
                disp(plateBBBB);
                disp(plateA);
                disp(plateAA);
                disp(plateB);
                disp(plateBB);
                disp(plateC);
                disp(plateCC);
                disp(plateCCC);
                disp(plateCCCC);
                break
            end
            A=fill(x,y,'b');
            AA=fill(xx,yy,'c');
            AAA=fill(xxx,yyy,'m');
            AAAA=fill(xxxx,yyyy,'y');
            B=fill(a,b,'b');
            BB=fill(aa,bb,'c');
            BBB=fill(aaa,bbb,'m');
            BBBB=fill(aaaa,bbbb,'y');
            C=fill(c,d,'b');
            CC=fill(cc,dd,'c');
            CCC=fill(ccc,ddd,'m');
            CCCC=fill(cccc,dddd,'y');
            set(A,'xdata',x,'ydata',y)
            set(AA,'xdata',xx,'ydata',yy)
            set(AAA,'xdata',xxx,'ydata',yyy)
            set(AAAA,'xdata',xxxx,'ydata',yyyy)
            set(B,'xdata',a,'ydata',b)
            set(BB,'xdata',aa,'ydata',bb)
            set(BBB,'xdata',aaa,'ydata',bbb)
            set(BBBB,'xdata',aaaa,'ydata',bbbb)
            set(C,'xdata',c,'ydata',d)
            set(CC,'xdata',cc,'ydata',dd)
            set(CCC,'xdata',ccc,'ydata',ddd)
            set(CCCC,'xdata',cccc,'ydata',dddd)
            pause(0.01)
            if yyy(1)>=20
                disp('You win!')
                break
            end
        end
        x0=x;
        xx0=xx;
        yyy0=yyy;
        yyyy0=yyyy;       
        a0=a;
        aa0=aa;
        bbb0=bbb;
        bbbb0=bbbb;
        c0=c;
        cc0=cc;
        ddd0=ddd;
        dddd0=dddd;
        circle(10.7+w,9.3,'y');
        circle(9.3,10.7+w,'y');
        for i=0:0.01:o
            x=x0+i;
            xx=xx0-i;
            yyy=yyy0+i;
            yyyy=yyyy0-i;
            a=a0+i;
            aa=aa0-i;
            bbb=bbb0+i;
            bbbb=bbbb0-i;
            c=c0+i;
            cc=cc0-i;
            ddd=ddd0+i;
            dddd=dddd0-i;
            if x(1)<=7.02 && x(1)>=6.97 && st==0
                if randi(round(1/p),1,1)==1
                    safe=false;               
                else
                    x0=x0-0.01;
                    xx0=xx0+0.01;
                    a0=a0-0.01;
                    aa0=aa0+0.01;
                    c0=c0-0.01;
                    cc0=cc0+0.01;                  
                end       
            elseif yyy(1)<=7.02 && yyy(1)>=6.97 && rd==0
                if randi(round(1/p),1,1)==1
                    safe=false;
                else
                    yyy0=yyy0-0.01;
                    yyyy0=yyyy0+0.01;
                    bbb0=bbb0-0.01;
                    bbbb0=bbbb0+0.01;
                    ddd0=ddd0-0.01;
                    dddd0=dddd0+0.01;
                end
            end
            if safe==false
                disp(plateAAA);
                disp(plateAAAA);
                disp(plateBBB);
                disp(plateBBBB);
                disp(plateA);
                disp(plateAA);
                disp(plateB);
                disp(plateBB);
                disp(plateC);
                disp(plateCC);
                disp(plateCCC);
                disp(plateCCCC);
                break
            end
            A=fill(x,y,'b');
            AA=fill(xx,yy,'c');
            AAA=fill(xxx,yyy,'m');
            AAAA=fill(xxxx,yyyy,'y');
            B=fill(a,b,'b');
            BB=fill(aa,bb,'c');
            BBB=fill(aaa,bbb,'m');
            BBBB=fill(aaaa,bbbb,'y');
            C=fill(c,d,'b');
            CC=fill(cc,dd,'c');
            CCC=fill(ccc,ddd,'m');
            CCCC=fill(cccc,dddd,'y');
            set(A,'xdata',x,'ydata',y)
            set(AA,'xdata',xx,'ydata',yy)
            set(AAA,'xdata',xxx,'ydata',yyy)
            set(AAAA,'xdata',xxxx,'ydata',yyyy)
            set(B,'xdata',a,'ydata',b)
            set(BB,'xdata',aa,'ydata',bb)
            set(BBB,'xdata',aaa,'ydata',bbb)
            set(BBBB,'xdata',aaaa,'ydata',bbbb)
            set(C,'xdata',c,'ydata',d)
            set(CC,'xdata',cc,'ydata',dd)
            set(CCC,'xdata',ccc,'ydata',ddd)
            set(CCCC,'xdata',cccc,'ydata',dddd)
            pause(0.01)
            if yyy(1)>=20
                disp('You win!')
                break
            end
        end
        x0=x;
        xx0=xx;
        yyy0=yyy;
        yyyy0=yyyy;       
        a0=a;
        aa0=aa;
        bbb0=bbb;
        bbbb0=bbbb;
        c0=c;
        cc0=cc;
        ddd0=ddd;
        dddd0=dddd;
        circle(9.3,9.3,'g');
        circle(10.7+w,10.7+w,'g');
        circle(10.7+w,9.3,'r');
        circle(9.3,10.7+w,'r');
        st=1;
        rd=0;
        disp(plateA);
        disp(plateAA);
        disp(plateB);
        disp(plateBB);
        disp(plateC);
        disp(plateCC);
        if yyy(1)>=20
            break
        end
    end
end