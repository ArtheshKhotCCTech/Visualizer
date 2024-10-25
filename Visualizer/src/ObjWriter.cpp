#include "ObjWriter.h"
#include<fstream>
#include<iomanip>

ObjWriter::ObjWriter() {

}

ObjWriter::~ObjWriter()
{
}

void ObjWriter::Write(const std::string& filename, const Triangulation& triangulation)
{
	std::ofstream outfile(filename);
    if (outfile.is_open()) {
        for (Triangle tri : triangulation.Triangles) {
            outfile << std::fixed << std::setprecision(6)
                << formulateText(triangulation, tri.P1())
                << formulateText(triangulation, tri.P2())
                << formulateText(triangulation, tri.P3());
        }
        for (Triangle tri : triangulation.Triangles) {
            outfile << std::fixed << std::setprecision(6)
                << formulateNormal(triangulation, tri.Normal());
        }
        for (Triangle tri : triangulation.Triangles) {
            outfile << "f "
                << std::to_string(uniqueData.indexOf(tri.P1())+1)
                << "//"
                << std::to_string(uniqueNormal.indexOf(tri.Normal()) + 1) << " "
                << std::to_string(uniqueData.indexOf(tri.P2()) + 1)
                << "//"
                << std::to_string(uniqueNormal.indexOf(tri.Normal()) + 1) << " "
                << std::to_string(uniqueData.indexOf(tri.P3()) + 1)
                << "//"
                << std::to_string(uniqueNormal.indexOf(tri.Normal()) + 1) << " "
                << "\n";
        }
    }
}

std::string ObjWriter::formulateText(Triangulation triangulation, Point point)
{
    if (!uniqueData.contains(point)) {
        uniqueData.push_back(point);
        double x = triangulation.UniqueNumbers[point.X()];
        double y = triangulation.UniqueNumbers[point.Y()];
        double z = triangulation.UniqueNumbers[point.Z()];


        return "v " + std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z) + "\n";
    }
    return "";
}

std::string ObjWriter::formulateNormal(Triangulation triangulation, Point point)
{
    if (!uniqueNormal.contains(point)) {
        uniqueNormal.push_back(point);
        double x = triangulation.UniqueNumbers[point.X()];
        double y = triangulation.UniqueNumbers[point.Y()];
        double z = triangulation.UniqueNumbers[point.Z()];

        return "vn " + std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z) + "\n";
    }
    return "";
}
