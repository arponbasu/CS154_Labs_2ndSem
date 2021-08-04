
#include <FL/Fl.H> // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Clock.H>

#include <iostream>
#include <string>

using namespace std;

int circleLeft;
int score;

int getRandomNumber(int lw,int hgh)
{

           int random_integer;
	   int lowest=lw, highest=hgh;
	   int range=(highest-lowest)+1;
           random_integer = lowest + rand() % range;
           return random_integer;
}





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

class MyCircle : public Shape {

int colorNum;
bool clicked;
int value;

public:
   void setValue(int num){
     value=num;
   }


   MyCircle (int x,int y,int w,int Num) : Shape (x,y,w, w) {
     colorNum=Num;
     clicked=false;
   }


    void setColor(int num){
             colorNum=num;
             fl_color(FL_GREEN);
            // draw();
    }
    virtual void draw() {
	//fl_color(fl_rgb_color(100));
        if(colorNum==0){
            fl_color(FL_BLUE);
        }
        else{
            fl_color(FL_GREEN);
        }
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
	                     fl_color(fl_rgb_color(130));
	                     fl_pie (x,y,w,h,0,360);
   }



   virtual int handle(int e) {
      if (e==FL_PUSH) {
          if(!clicked){
              wipe();
              circleLeft=circleLeft-1;
              score=score+value;
              clicked=true;
              fl_font(FL_HELVETICA,20);
              char txt[256];
              sprintf(txt,"Circles Left:%d,Last Point: %d, Your Score : %d",circleLeft,value,score );
              //resize(50,500,300,50);
              fl_draw_box (FL_FLAT_BOX,0,500,600,100,FL_WHITE);

              fl_color(FL_RED);
              fl_draw(txt, 50, 550);

              if(circleLeft==0){
                fl_font(FL_HELVETICA,30);
                char txt1[256];
                sprintf(txt,"Game Over.Your Score : %d",score );
                fl_draw(txt, 100, 400);
              }

            }
       }
       return 0;
  }




};





int main(int argc, char *argv[]) {


Fl_Window *window;
window = new Fl_Window (600,600,"A Simple Game"); // outer window

circleLeft=30;
score=0;
//MyRectangle *r =new MyRectangle(10,500,40,40);


       for (int i=0; i<10; i++) {
           MyCircle *cir=new MyCircle(20+i*50,300, 35,0);
           cir->setValue(getRandomNumber(-10,10));
	}

	for (int i=0; i<10; i++) {
           MyCircle *cir=new MyCircle(20+i*50,200, 35,0);
           cir->setValue(getRandomNumber(-10,10));
	}

       for (int i=0; i<10; i++) {
           MyCircle *cir=new MyCircle(20+i*50,100, 35,0);
           cir->setValue(getRandomNumber(-10,10));
	}

	    window->color(FL_WHITE);
    	window->end();
    	window->show();


    	return(Fl::run());  // the process waits from here on for events
}
