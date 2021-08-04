/*
#include <bits/stdc++.h>

#include <FL/Fl.H> // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Button.H> // needed to use the Fl_Box class




using namespace std;



char* int2charstar (int v) {
 char *s = new char[sizeof(int)];
 sprintf(s,"%d",v);
 return s;
};

void swap (const char*& x, const char*& y){
  const char* temp = x;
    x = y;
    y = temp;
}

class MyButton : public Fl_Button {
	int count;
	public:
		MyButton (int x, int y, int w, int h, const char *l);
		int handle(int e); // e is incoming mouse event of different kinds
    int getCount ();
    void setCount (int);
    void whenClicked(MyButton***, void*);
 };

MyButton :: MyButton (int x,int y, int w, int h, const char *l) : Fl_Button (x,y,w,h,l) {
	count = 0;
}
int MyButton :: handle (int e) {
if(e == FL_PUSH)	count++;
  return 1;
}
int MyButton :: getCount () {
  return count;
}
void MyButton :: setCount (int cnt) {
count = cnt;
}


void MyButton::whenClicked(MyButton*** buttons)
{
  for (int i = 0; i < 4; i++){
      for(int j = 0; j < 4; j++){

              if(buttons[i][j]->getCount() > 0){
                const char* var;
                var = buttons[i][j]->label();
                const char* empty = "";
                if (i > 0 && buttons[i-1][j]->label() == empty) {
                  buttons[i][j]->label("");
                  buttons[i-1][j]->label(var);
                }
                else if (buttons[i+1][j]->label() == empty) {
                  buttons[i][j]->label("");
                  buttons[i+1][j]->label(var);
                }
                else if (buttons[i][j+1]->label() == empty) {
                  buttons[i][j]->label("");
                  buttons[i][j+1]->label(var);
                }
                else if (j > 0 && buttons[i][j-1]->label() == empty) {
                  buttons[i][j]->label("");
                  buttons[i][j-1]->label(var);
                }
              }
              buttons[i][j]->setCount(0);
              break;
      }
    }

}




int main(int argc, char *argv[]) {

Fl_Window *window;

window = new Fl_Window (600,600,"DEMO"); // outer window

MyButton* buttons[4][4];

for (int i = 0; i < 4; i++){
  for(int j = 0; j < 4; j++){

    int a = i+4*j+1;
    if (a != 16) {
                  buttons[i][j] = new MyButton(50*(2*i+1),50*(2*j+1),100,100,"Err");
                  buttons[i][j]->label(int2charstar(a));
                //  buttons[i][j]->when(FL_WHEN_CHANGED);
                //  buttons[i][j]->callback(( Fl_Callback* ) click_callback);

                }

    else {
           buttons[i][j] = new MyButton(50*(2*i+1),50*(2*j+1),100,100,"Err");
           buttons[i][j]->label("");
        //  buttons[i][j]->callback(( Fl_Callback* ) click_callback);


        }
  }
}
for (int i = 0; i < 4; i++){
  for(int j = 0; j < 4; j++){
    buttons[i][j]->whenClicked(buttons);
  }
}

//MyButton->callback(whenClicked);
/*

    for (int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){

                if(buttons[i][j]->getCount() > 0){
                  const char* var;
                  var = buttons[i][j]->label();
                  const char* empty = "";
                  if (i > 0 && buttons[i-1][j]->label() == empty) {
                    buttons[i][j]->label("");
                    buttons[i-1][j]->label(var);
                  }
                  else if (buttons[i+1][j]->label() == empty) {
                    buttons[i][j]->label("");
                    buttons[i+1][j]->label(var);
                  }
                  else if (buttons[i][j+1]->label() == empty) {
                    buttons[i][j]->label("");
                    buttons[i][j+1]->label(var);
                  }
                  else if (j > 0 && buttons[i][j-1]->label() == empty) {
                    buttons[i][j]->label("");
                    buttons[i][j-1]->label(var);
                  }
                }
                buttons[i][j]->setCount(0);
                break;
        }
      }






      window->color(FL_WHITE);
    	window->end();
    	window->show();
      int retval = Fl::run();

      cout << "Exiting...\n";
      return retval;  // the process waits from here on for events
}



static void button_cb(Fl_Button* buttonptr,void* userdata){
cout<<(const char*)userdata<<buttonptr->label()  <<endl;
if (buttonptr->color() == FL_BLUE) {
buttonptr->color(FL_RED); //toggle
}else {
buttonptr->color(FL_BLUE);//toggle
}
}
*/
#include <bits/stdc++.h>

#include <FL/Fl.H> // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Button.H> // needed to use the Fl_Box class

using namespace std;


char* int2charstar (int v) {
 char *s = new char[sizeof(int)];
 sprintf(s,"%d",v);
 return s;
};

//Fl_Button* buttons[4][4];

class MyWindow : public Fl_Window
{
public:
MyWindow(int width, int height, const char* title=0) :
Fl_Window(width,height,title){

color(FL_WHITE);
// Begin adding children to this window
begin();
//Create a button - x , y , width, height, label

Fl_Button* buttons[4][4];

for (int i = 0; i < 4; i++){
  for(int j = 0; j < 4; j++){

    int a = i+4*j+1;
    if(a != 16){
        buttons[i][j] = new Fl_Button(50*(2*i+1),50*(2*j+1),100,100,"");
        buttons[i][j]->label(int2charstar(a));
        //buttons[i][j]->callback((Fl_Callback*)button_cb,(void *)"My Button");
    }
    else{
      buttons[i][j] = new Fl_Button(50*(2*i+1),50*(2*j+1),100,100,"");
    //  buttons[i][j]->callback((Fl_Callback*)button_cb,(void *)"My Button");


    }




            }
          }

          for (int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){

                  buttons[i][j]->callback((Fl_Callback*)button_cb,(void *)buttons);
                  break;

                      }
                    }






// Set color of button to red
//button1->color(FL_RED);
 // Stop adding children to this window
 end();
 // Display the window
 show();
 }

 static void button_cb(Fl_Button* buttonptr,void* userdata){
   Fl_Button*** buttons;
   buttons = (Fl_Button***)userdata;
   const char* var;
   var = buttons[i][j]->label();
   const char* empty = "";
   if (i > 0 && buttons[i-1][j]->label() == empty) {
     buttons[i][j]->label("");
     buttons[i-1][j]->label(var);
   }
   else if (buttons[i+1][j]->label() == empty) {
     buttons[i][j]->label("");
     buttons[i+1][j]->label(var);
   }
   else if (buttons[i][j+1]->label() == empty) {
     buttons[i][j]->label("");
     buttons[i][j+1]->label(var);
   }
   else if (j > 0 && buttons[i][j-1]->label() == empty) {
     buttons[i][j]->label("");
     buttons[i][j-1]->label(var);
   }
 }



}



};











int main()
{
   MyWindow win(600,600,"Game Window");

   return Fl::run();

}
