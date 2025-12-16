#ifndef OBJECT_H
#define OBJECT_H
class Object{
public:
	Object(int mx, int my) :x(mx), y(my){}
	virtual void draw() = 0;
	int getX(){ return x; }
	int getY(){ return y; }
	void setImage();
protected:
	int x;
	int y;
};
#endif