#include <FL/Fl.H> // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <Fl/Fl_Timer.H>

#include <bits/stdc++.h>
#include <sys/wait.h>
#include <unistd.h>



class Shape : public Fl_Widget  {
  	protected:
	int x, y, w, h, col;
	public:
		Shape (int x, int y, int w, int h, int col) : Fl_Widget (x,y,w,h){
			this->x=x; this->y=y;
			this->w=w; this->h=h;
      this->col=col;
		}
		virtual void wipe()=0;
		virtual void refresh(int dx, int dy)=0;
		virtual int handle(int e) {

      if (e==FL_KEYDOWN) {
        if(Fl::event_key() == FL_Right){
          //wipe();
  				refresh(10,0);
        }
        else if(Fl::event_key() == FL_Left){
          //wipe();
  				refresh(-10,0);
        }
        else if(Fl::event_key() == FL_Up){
          //wipe();
  				refresh(0,-10);
        }
        else if(Fl::event_key() == FL_Down){
        //  wipe();
  				refresh(0,10);
        }
        else if(Fl::event_key() == 'e'){
        //  wipe();
          col = 55;
  				//refresh(0,10);
        }
        else if(Fl::event_key() == 'w'){
        //  wipe();
          col = 120;
  				//refresh(0,10);
        }
        else if(Fl::event_key() == '1'){
          //wipe();
          refresh(1,-1);
        }
        else if(Fl::event_key() == '2'){
          //wipe();
          refresh(-1,-1);
        }
        else if(Fl::event_key() == '3'){
          //wipe();
          refresh(-1,1);
        }
        else if(Fl::event_key() == '4'){
        //  wipe();
          refresh(1,1);
        }




			}
			return 1;
		}
    virtual void move()=0;

};

class MyRectangle : public Shape {
 public:
   MyRectangle (int x,int y,int w, int h, int col) : Shape (x,y,w,h,col) { }
   virtual void draw() {
	fl_draw_box (FL_FLAT_BOX,x,y,w,h,col);
   }

   virtual void wipe() {
	fl_draw_box (FL_FLAT_BOX,x,y,w,h,FL_WHITE);
   }

   virtual void refresh(int dx, int dy) {
	x=x+dx;y=y+dy;
	resize(x,y,w,h);
	fl_draw_box (FL_FLAT_BOX,x,y,w,h,col);
   }
   virtual void  move() {
     this->wipe();
     this->refresh(10,0);
   }
};

class MyCircle : public Shape {
 public:
   MyCircle (int x,int y,int w,int col) : Shape (x,y,w+100, w+20,col) { }
    virtual void draw() {
	fl_color(fl_rgb_color(130));
	fl_pie (x,y,w,h,0,360);
   }
   virtual void wipe() {
	fl_color(FL_WHITE);
	fl_pie (x,y,w,h,0,360);

   }
   virtual void refresh(int dx, int dy) {
	x=x+dx;y=y+dy;
	resize(x,y,w,h);
	fl_color(fl_rgb_color(130));
	fl_pie (x,y,w,h,0,360);
   }
};




int main(int argc, char *argv[]) {
Fl_Window *window;
window = new Fl_Window (600,600,"DEMO"); // outer window
	for (int i=0; i<1; i++) {
           new MyRectangle(100+i*100,100+i*100,10,10,120);
           //new MyCircle(300,300+i*100, 35);
	}


  window->color(FL_WHITE);
    	window->end();
    	window->show();

    	return(Fl::run());  // the process waits from here on for events
}
