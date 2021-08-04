#include <FL/Fl.H> // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Clock.H>

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;



int cnt;


class Shape : public Fl_Widget  {
  	protected:
	int x, y, w, h;
	public:
		Shape (int x, int y, int w, int h) : Fl_Widget (x,y,w,h){
			this->x=x; this->y=y;
			this->w=w; this->h=h;
		}
		virtual void wipe()=0;
		virtual void refresh(int dx, int dy)=0;

};

class MyRectangle : public Shape {

//int x,y;
int top_x,top_y;

public:
   MyRectangle (int x,int y,int w, int h) : Shape (x,y,w,h) {
    	top_x=x;
       	top_y=y;

   }
   virtual void draw() {
	     fl_draw_box (FL_FLAT_BOX,top_x,top_y,w,h,120);
   }

   virtual void wipe() {
	    fl_draw_box (FL_FLAT_BOX,top_x,top_y,w,h,FL_WHITE);
   }

   virtual void refresh(int dx, int dy) {
	     top_x=top_x+dx;
       top_y=top_y+dy;
	      resize(top_x,top_y,w,h);
	      fl_draw_box (FL_FLAT_BOX,top_x,top_y,w,h,120);
   }








   virtual int handle(int e) {
			if (e==FL_PUSH) {

				                        wipe();
                                if(Fl::event_button()==FL_LEFT_MOUSE){
				                                refresh(10,0);
                                }
                                else if(Fl::event_button()==FL_RIGHT_MOUSE){
                                 refresh(-10,0);
                                }
			}
                        if(e==FL_KEYUP )
                        {
				                        wipe();
                               if(Fl::event_key()==FL_Left){
                                    //wipe();
				                            refresh(-10,0);
                                }
                                else if(Fl::event_key()==FL_Right){

				                               // wipe();
				                                refresh(10,0);
                                }
                              else if(Fl::event_key()==FL_Down){

				                                 // wipe();
				                                  refresh(0,10);
                                }
                              else if(Fl::event_key()==FL_Up){
				                                //wipe();
				                                refresh(0,-10);
                                }

                        }
			return 1;
		};



};

class MyCircle : public Shape
{

int colorNum;
bool clicked;
int value;
int vx;
int vy;

public:
    void setVelocity(int vx, int vy){
     this->vx=vx; this->vy=vy;

   }
   int getVelocityx(){
     return vx;

   }
   int getVelocityy(){
     return vy;

   }
   /*
   MyCircle () : Shape (x,y,w, w) {
     clicked=false;
   }*/
   MyCircle (int x,int y,int w,int Num) : Shape (x,y,w, w) {
     colorNum=Num;
     clicked=false;
   }


    void setColor(int num){
             colorNum=num;


    }
    virtual void draw() {
	     fl_color(colorNum);
       /*
        if(colorNum==0){
            fl_color(FL_BLUE);
        }
        else{
            fl_color(FL_GREEN);
        }*/
	       fl_pie (x,y,w,h,0,360);
   }

   virtual void wipe() {
	       fl_color(FL_WHITE);
	       fl_pie (x,y,w,h,0,360);
    }

   virtual void refresh(int dx, int dy) {
	                     x=x+dx;
                       y=y+dy;
	                     resize(x,y,w,h);
	                     fl_color(fl_rgb_color(this->colorNum));
	                     fl_pie (x,y,w,h,0,360);
   }



   virtual int handle(int e) {
      if (e==FL_PUSH) {}
       return 0;
  }




};


void testCallback(void *userdata)
{

  MyCircle* circle = (MyCircle*)(userdata);
  circle->wipe();
  circle->refresh(circle->getVelocityx(),circle->getVelocityy());
  Fl::repeat_timeout(0.05, testCallback, userdata);

}



class MyTimer  {
    bool running;
    static  void Timer_CB(void *userdata) {}
public:
    // CONSTRUCTOR
    MyTimer()  {
        running = false;
        cnt = 0;
        //Fl::add_timeout(0.25, Timer_CB, (void*)this);
    }

    void startTimer(void *userdata){
      running=true;
      Fl::repeat_timeout(1.0, testCallback, userdata);
    }
    void stopTimer(){
      running=false;
    }
    virtual void onTimeout(){}
};



MyCircle* cir;
vector<MyCircle*> circleArray;







int main(int argc, char *argv[]) {

srand(time(NULL));

Fl_Window *window;
int n = 100;
window = new Fl_Window (600,600,"A Simple Game"); // outer window
for (int i = 0; i < n; i++){
  MyCircle* temp = new MyCircle(300+50*(rand()%3),300+50*(rand()%3), 35,0);
  temp->setVelocity(rand()%5,0.2*(rand()%10));
  temp->setColor(rand()%255);
  circleArray.push_back(temp);
}

  //cir = new MyCircle(150,10, 35,0);
  //cir->setVelocity(0,5);






      MyTimer  timer;

      //timer.startTimer(cir);
      timer.startTimer(circleArray.back());
      for (int i = 0; i < circleArray.size(); i++){
        auto val = circleArray.back();
        circleArray.pop_back();
        timer.startTimer(val);
      }



	    window->color(FL_WHITE);
    	window->end();
    	window->show();
    	return(Fl::run());
}
