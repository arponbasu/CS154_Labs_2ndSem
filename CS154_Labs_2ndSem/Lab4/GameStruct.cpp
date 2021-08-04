#include <bits/stdc++.h>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>

using namespace std;


char* int2charstar (int v) {
 char *s = new char[sizeof(int)];
 sprintf(s,"%d",v);
 return s;
}

class ButtonData{
public:
  int id;
  int I;
  int J;
  char* Label;
  ButtonData* neighbours[4];
  ButtonData();
  ButtonData(int i);
};

ButtonData::ButtonData(int i){
    id = i;
}

class MyWindow : public Fl_Window
{
public:
MyWindow(int width, int height, const char* title=0) :
Fl_Window(width,height,title){

color(FL_WHITE);

begin();


Fl_Button* buttons[16];
ButtonData* data[16];

for (int k = 0; k < 16; k++){

    int i = k%4;
    int j = (k - i)/4;

        buttons[k] = new Fl_Button(100+50*(2*i+1),50*(2*j+1),100,100,"");
        ButtonData *bd = new ButtonData();
        bd->id = k + 1;
        bd->I = i;
        bd->J = j;
        bd->Label = int2charstar(bd->id);
        buttons[k]->label(bd->Label);
        data[k] = bd;


    }

    for (int k = 0; k < 16; k++){
      buttons[k]->callback((Fl_Callback*)buttons[k],(void *)data[k]);
}






 end();
 show();
 }

 static void button_cb(Fl_Button* buttonptr,void* userparameter){
 ButtonData* bd = new ButtonData();
 bd = (ButtonData*)userparameter;









 }



};











int main()
{
   MyWindow win(600,600,"Game Window");
   return Fl::run();
}
