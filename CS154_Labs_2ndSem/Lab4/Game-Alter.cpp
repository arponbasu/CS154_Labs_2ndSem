#include <bits/stdc++.h>

#include <FL/Fl.H> // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Button.H> // needed to use the Fl_Box class
#include<string>



using namespace std;


char* int2charstar (int v) {
 char *s = new char[sizeof(int)];
 sprintf(s,"%d",v);
 return s;
};



class MyWindow : public Fl_Window
{
public:
MyWindow(int width, int height, const char* title=0) :
Fl_Window(width,height,title)
{
// Set color of window to white
color(FL_WHITE);
// Begin adding children to this window
begin();
//Create a button - x , y , width, height, label
//Fl_Button *button1 = new Fl_Button(25,15,140,40,"OK");

Fl_Button * buttons[4][4];

for (int i = 0; i < 4; i++)
{
  for(int j = 0; j < 4; j++)
  {

    int a = i+4*j+1;

                  buttons[i][j] = new Fl_Button(50*(2*i+1),50*(2*j+1),100,100,"Err");
                   buttons[i][j]->color(FL_BLUE);
                   buttons[i][j]->label(int2charstar(a));
                 buttons[i][j]->callback((Fl_Callback*)button_cb,(void *)"My Button");


                //  buttons[i][j]->when(FL_WHEN_CHANGED);
                //  buttons[i][j]->callback(( Fl_Callback* ) click_callback);

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
 cout<<(const char*)userdata<<buttonptr->label()  <<endl;
 if (buttonptr->color() == FL_BLUE) {
 buttonptr->color(FL_RED); //toggle
 }else {
 buttonptr->color(FL_BLUE);//toggle
 }
 }



};











int main()
{

  // Create a window with our new class - width, height, label (=title)
   MyWindow win(600,600,"Game Window");
   // Run and return
   return Fl::run();

}
