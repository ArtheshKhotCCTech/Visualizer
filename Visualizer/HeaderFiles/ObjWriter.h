#pragma once
#include "Writer.h"
#include<QVector>

class ObjWriter : public Writer
{
public:
	ObjWriter();
	~ObjWriter();
	
	void Write(const std::string& filename, const Triangulation& trianglation);
	std::string formulateText(Triangulation triangulation, Point point);
	std::string formulateNormal(Triangulation triangulation, Point point);
private:
	QVector<Point> uniqueData;
	QVector<Point> uniqueNormal;
};

