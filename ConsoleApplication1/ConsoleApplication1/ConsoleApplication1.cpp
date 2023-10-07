// BetaProj.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <ogr\ogrsf_frmts\ogrsf_frmts.h>
/*int main()
{
const char *pszDriverName = "ESRI Shapefile";
GDALDriver *poDriver;
GDALAllRegister();
//OGRGeomFieldDefn oPointField("PointField", wkbPoint);
OGRSpatialReference* poSRS = new OGRSpatialReference();
poSRS->importFromEPSG(4326);
//oPointField.SetSpatialRef(poSRS);
//poSRS->Release();
poDriver = GetGDALDriverManager()->GetDriverByName(pszDriverName);
if (poDriver == NULL)
{
printf("%s driver not available.\n", pszDriverName);
exit(1);
}
GDALDataset *poDS;
poDS = poDriver->Create("point_out.shp", 0, 0, 0, GDT_Unknown, NULL);
if (poDS == NULL)
{
printf("Creation of output file failed.\n");
exit(1);
}
OGRLayer *poLayer;
poLayer = poDS->CreateLayer("point_out", NULL, wkbPoint, NULL);
if (poLayer == NULL)
{
printf("Layer creation failed.\n");
exit(1);
}
OGRFieldDefn oField("Name", OFTString);
oField.SetWidth(32);
if (poLayer->CreateField(&oField) != OGRERR_NONE)
{
printf("Creating Name field failed.\n");
exit(1);
}
double x, y; char szName[33];
while (!feof(stdin) && fscanf_s(stdin, "%lf,%lf,%32s", &x, &y, szName) == 3)
{
OGRFeature *poFeature;
poFeature = OGRFeature::CreateFeature(poLayer->GetLayerDefn());
poFeature->SetField("Name", szName);
OGRPoint pt;
//pt.assignSpatialReference(poSRS);
//pt.set3D(new OGRPoint(90, 0, 0));
pt.setX(x); pt.setY(y);
poFeature->SetGeometry(&pt);
if (poLayer->CreateFeature(poFeature) != OGRERR_NONE)
{
printf("Failed to create feature in shapefile.\n");
exit(1);
}
OGRFeature::DestroyFeature(poFeature);
}
GDALClose(poDS);
}*/
/*
int main()
{
//GDALAllRegister();
OGRRegisterAll();
double lat1 = 40.7128; // Latitude of point 1 (New York City)
double lon1 = -74.0060; // Longitude of point 1 (New York City)
double lat2 = 34.0522; // Latitude of point 2 (Los Angeles)
double lon2 = -118.2437; // Longitude of point 2 (Los Angeles)
double lat3 = 50.7128; // Latitude of point 3 (New York City)
double lon3 = -78.0060; // Longitude of point 3(New York City)
//double distance = calculateDistance(lat1,
lon1, lat2, lon2);
//std::cout << "Distance between the two
points: " << distance << " km" << std::endl;
std::string filename = "points.shp";
const char* driverName = "ESRI Shapefile";
GDALDriver* driver = GetGDALDriverManager()->GetDriverByName(driverName);
if (driver == nullptr)
{
printf("%s driver not available.\n", driverName);
exit(1);
}
GDALDataset* dataset = driver->Create(filename.c_str(), 0, 0, 0, GDT_Unknown, nullptr);
if (dataset == nullptr)
{
printf("%s driver not available.\n");
exit(1);
}
OGRSpatialReference srs;
srs.SetWellKnownGeogCS("WGS84");
OGRLayer* layer = dataset->CreateLayer("points", &srs, wkbPoint);
if (layer == nullptr)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
OGRFieldDefn fieldDefn("ID", OFTInteger);
if (layer->CreateField(&fieldDefn) != OGRERR_NONE)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
OGRFeature* feature = OGRFeature::CreateFeature(layer->GetLayerDefn());
feature->SetField("ID", 1);
OGRPoint point1(lon1, lat1);
OGRPoint point2(lon2, lat2);
OGRPoint point3(lon3, lat3);
OGRLineString line1;
line1.addPoint(lon1, lat1);
line1.addPoint(lon2, lat2);
line1.addPoint(lon3, lat3);
feature->SetGeometry(&point1);
if (layer->CreateFeature(feature) != OGRERR_NONE)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
feature->SetGeometry(&point2);
if (layer->CreateFeature(feature) != OGRERR_NONE)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
feature->SetGeometry(&point3);
if (layer->CreateFeature(feature) != OGRERR_NONE)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
OGRFeature::DestroyFeature(feature);
printf("%s Shape file has been created\n", filename);
GDALClose(dataset);
}*/
/*
int main()
{
GDALAllRegister();
OGRRegisterAll();
double lat1 = -20; //40.7128; // Latitude of point 1 (New York City)
double lon1 = 0;//-74.0060; // Longitude of point 1 (New York City)
double lat2 = 20;// 34.0522; // Latitude of point 2 (Los Angeles)
double lon2 = 0;// -118.2437; // Longitude of point 2 (Los Angeles)
double lat3 = 0;
double lon3 = -20;
double lat4 = 0;
double lon4 = 20;
//double distance = calculateDistance(lat1,
lon1, lat2, lon2);
//std::cout << "Distance between the two
points: " << distance << " km" << std::endl;
std::string filename = "lines.shp";
const char* driverName = "ESRI Shapefile";
GDALDriver* driver = GetGDALDriverManager()->GetDriverByName(driverName);
if (driver == nullptr)
{
printf("%s driver not available.\n", driverName);
exit(1);
}
GDALDataset* dataset = driver->Create(filename.c_str(), 0, 0, 0, GDT_Unknown, nullptr);
if (dataset == nullptr)
{
printf("%s driver not available.\n");
exit(1);
}
OGRSpatialReference srs;
srs.SetWellKnownGeogCS("WGS84");
OGRLayer* layer = dataset->CreateLayer("lines", &srs, wkbLineString);
if (layer == nullptr)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
OGRFieldDefn fieldDefn("ID", OFTInteger);
if (layer->CreateField(&fieldDefn) != OGRERR_NONE)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
OGRFeature* feature = OGRFeature::CreateFeature(layer->GetLayerDefn());
feature->SetField("ID", 1);
OGRLineString line1;
line1.addPoint(lon1, lat1);
line1.addPoint(lon2, lat2);
line1.toLineString();
feature->SetGeometry(&line1);
if (layer->CreateFeature(feature) != OGRERR_NONE)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
//OGRFieldDefn fieldDefn2("ID2", OFTInteger);
//OGRFeature* feature2 = OGRFeature::CreateFeature(layer->GetLayerDefn());
feature->SetField("ID", 2);
OGRLineString line2;
line2.addPoint(lon3, lat3);
line2.addPoint(lon4, lat4);
line2.toLineString();
feature->SetGeometry(&line2);
OGRFeature::DestroyFeature(feature);
//OGRFeature::DestroyFeature(feature2);
printf("%s Shape file has been created\n", filename);
GDALClose(dataset);
}
*/
//code for generating line and point in same code
/*
int main()
{
//GDALAllRegister();
OGRRegisterAll();
double lat1 = 40.7128; // Latitude of point 1 (New York City)
double lon1 = -74.0060; // Longitude of point 1 (New York City)
double lat2 = 34.0522; // Latitude of point 2 (Los Angeles)
double lon2 = -118.2437; // Longitude of point 2 (Los Angeles)
//double distance = calculateDistance(lat1,
lon1, lat2, lon2);
//std::cout << "Distance between the two
points: " << distance << " km" << std::endl;
std::string filename = "features1.shp";
const char* driverName = "ESRI Shapefile";
GDALDriver* driver = GetGDALDriverManager()->GetDriverByName(driverName);
if (driver == nullptr)
{
printf("%s driver not available.\n", driverName);
exit(1);
}
GDALDataset* dataset = driver->Create(filename.c_str(), 0, 0, 0, GDT_Unknown, nullptr);
if (dataset == nullptr)
{
printf("%s driver not available.\n");
exit(1);
}
OGRSpatialReference srs;
srs.SetWellKnownGeogCS("WGS84");
OGRLayer* layer = dataset->CreateLayer("points", &srs, wkbPoint);
if (layer == nullptr)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
OGRFieldDefn fieldDefn("ID", OFTInteger);
if (layer->CreateField(&fieldDefn) != OGRERR_NONE)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
OGRFeature* feature = OGRFeature::CreateFeature(layer->GetLayerDefn());
feature->SetField("ID", 1);
OGRPoint point1(lon1, lat1);
OGRPoint point2(lon2, lat2);
feature->SetGeometry(&point1);
if (layer->CreateFeature(feature) != OGRERR_NONE)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
feature->SetGeometry(&point2);
if (layer->CreateFeature(feature) != OGRERR_NONE)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
OGRLineString line;
line.addPoint(lon1, lat1);
line.addPoint(lon2, lat2);
//line.toLineString();
OGRLayer* lineLayer = dataset->CreateLayer("lines", &srs, wkbLineString);
if (lineLayer == nullptr)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
OGRFeature* lineFeature = OGRFeature::CreateFeature(lineLayer->GetLayerDefn());
lineFeature->SetGeometry(&line);
if (lineLayer->CreateFeature(lineFeature) != OGRERR_NONE)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
OGRFeature::DestroyFeature(feature);
OGRFeature::DestroyFeature(lineFeature);
//GDALClose(dataset);
printf("%s Shape file has been created\n", filename);
GDALClose(dataset);
}
*/
//code for coordinate csv file and lines but giving error
//code is running for csv file and generating many point
//------------------------start----------code 4-----------start----------code4---------------------start------------------
/*
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
//commented header file
#include "gdal/gdal.h"
#include "gdal/gdal_priv.h"
#include "gdal/ogr_geometry.h"
#include "gdal/ogr_spatialref.h"
double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
const double earthRadius = 6371.0; // Earth radius in kilometers
double dlat = (lat2 - lat1) * (M_PI / 180.0); double dlon = (lon2 - lon1) * (M_PI / 180.0);
double a = sin(dlat / 2.0) * sin(dlat / 2.0) + cos(lat1 * (M_PI / 180.0)) * cos(lat2 * (M_PI /
180.0)) * sin(dlon / 2.0) * sin(dlon / 2.0);
double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));
double distance = earthRadius * c;
return distance;
}
void createPointShapefile(const std::string& filename, const std::vector<double>& latitudes, const
std::vector<double>& longitudes)
{
OGRRegisterAll();
const char* driverName = "ESRI Shapefile";
GDALDriver* driver = GetGDALDriverManager()->GetDriverByName(driverName);
if (driver == nullptr)
{
printf("%s driver not available.\n", driverName);
exit(1);
}
GDALDataset* dataset = driver->Create(filename.c_str(), 0, 0, 0, GDT_Unknown, nullptr);
if (dataset == nullptr)
{
printf("%s driver not available.\n");
exit(1);
}
OGRSpatialReference srs;
srs.SetWellKnownGeogCS("WGS84");
OGRLayer* layer = dataset->CreateLayer("points", &srs, wkbPoint);
if (layer == nullptr)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
OGRFieldDefn fieldDefn("ID", OFTInteger);
if (layer->CreateField(&fieldDefn) != OGRERR_NONE)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
OGRFeature* feature = OGRFeature::CreateFeature(layer->GetLayerDefn());
feature->SetField("ID", 1);
for (int i = 0; i < latitudes.size(); ++i)
{
OGRPoint point(longitudes[i], latitudes[i]);
feature->SetGeometry(&point);
std::cout << " Point created: " << i << std::endl;
if (layer->CreateFeature(feature) != OGRERR_NONE)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
}
OGRFeature::DestroyFeature(feature);
GDALClose(dataset);
std::cout << " Point Shapefile created: " << filename << std::endl;
}
void createLineShapefile(const std::string& filename, const std::vector<double>& latitudes, const
std::vector<double>& longitudes)
{
OGRRegisterAll();
const char* driverName = "ESRI Shapefile";
GDALDriver* driver = GetGDALDriverManager()->GetDriverByName(driverName);
if (driver == nullptr)
{
printf("%s driver not available.\n", driverName);
exit(1);
}
GDALDataset* dataset = driver->Create(filename.c_str(), 0, 0, 0, GDT_Unknown, nullptr);
if (dataset == nullptr)
{
printf("%s driver not available.\n");
exit(1);
}
OGRSpatialReference srs;
srs.SetWellKnownGeogCS("WGS84");
OGRLayer* layer = dataset->CreateLayer("lines", &srs, wkbLineString);
if (layer == nullptr)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
OGRFieldDefn fieldDefn("ID", OFTInteger);
if (layer->CreateField(&fieldDefn) != OGRERR_NONE)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
for (int i = 0; i < latitudes.size(); ++i) {
OGRFeature* feature = OGRFeature::CreateFeature(layer->GetLayerDefn());
feature->SetField("ID", i + 1);
OGRPoint point(longitudes[i], latitudes[i]);
OGRLineString line;
line.addPoint(longitudes[i], latitudes[i]);
line.addPoint(longitudes[i+1], latitudes[i+1]);
feature->SetGeometry(&line);
if (layer->CreateFeature(feature) != OGRERR_NONE)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
OGRFeature::DestroyFeature(feature);
}
GDALClose(dataset);
std::cout << " Line Shapefile created: " << filename << std::endl;
}
int main() {
GDALAllRegister();
std::string filename = "coordinates.csv"; //"D:\\BetaProj\\BetaProj\\coordinates.csv"; //
CSV file containing latitude and longitude coordinates
std::ifstream file(filename);
if (!file)
{
std::cerr << "Failed to open file: " << filename << std::endl;
return 1;
}
std::vector<double> latitudes;
std::vector<double> longitudes;
std::string line;
while (std::getline(file, line))
{
std::istringstream iss(line);
std::string lat, lon;
if (std::getline(iss, lat, ',') && std::getline(iss, lon, ','))
{
double latitude = std::stod(lat);
double longitude = std::stod(lon);
latitudes.push_back(latitude);
longitudes.push_back(longitude);
}
}
if (latitudes.empty() || longitudes.empty())
{
std::cerr << "No coordinates found in the file." << std::endl;
return 1;
}
std::cout << "Total coordinates: " << latitudes.size() << std::endl;
std::string outputFilename = "pointsss.shp";
createPointShapefile(outputFilename, latitudes, longitudes);
//createLineShapefile(outputFilename, latitudes, longitudes);
return 0;
}*/
//---------------end-------------------code 4------------end--------------------------------end----------------
//----------mayuressh sir---------------code 5--------start-----------------start--------------------start----------
/*#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "ogr_geometry.h"
#include "ogr_feature.h"
#include "ogr_core.h"
//commented header file
double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
const double earthRadius = 6371.0; // Earth radius in kilometers
double dlat = (lat2 - lat1) * (M_PI / 180.0); double dlon = (lon2 - lon1) * (M_PI / 180.0);
double a = sin(dlat / 2.0) * sin(dlat / 2.0) + cos(lat1 * (M_PI / 180.0)) * cos(lat2 * (M_PI /
180.0)) * sin(dlon / 2.0) * sin(dlon / 2.0);
double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));
double distance = earthRadius * c;
return distance;
}
GDALDataset* createPointShapefile(const std::string& filename, const std::vector<double>&
latitudes, const std::vector<double>& longitudes, GDALDataset* dataset)
{
OGRSpatialReference srs;
srs.SetWellKnownGeogCS("WGS84");
OGRLayer* layer = dataset->CreateLayer("points", &srs, wkbPoint);
if (layer == nullptr)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
OGRFieldDefn fieldDefn("ID", OFTInteger);
if (layer->CreateField(&fieldDefn) != OGRERR_NONE)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
OGRFeature* feature = OGRFeature::CreateFeature(layer->GetLayerDefn());
for (int i = 0; i < latitudes.size(); ++i)
{
feature->SetField("ID", i+1);
OGRPoint point(longitudes[i], latitudes[i]);
feature->SetGeometry(&point);
std::cout << " Point created: " << i << std::endl;
if (layer->CreateFeature(feature) != OGRERR_NONE)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
}
OGRFeature::DestroyFeature(feature);
//GDALClose(dataset);
//std::cout << " Point Shapefile created: " << filename << std::endl;
return dataset;
}
GDALDataset* createLineShapefile(const std::string& filename, const std::vector<double>&
latitudes, const std::vector<double>& longitudes, GDALDataset* dataset)
{
OGRSpatialReference srs;
srs.SetWellKnownGeogCS("WGS84");
OGRLayer* layer1 = dataset->CreateLayer("lines", &srs, wkbMultiLineString);
if (layer1 == nullptr)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
OGRFieldDefn fieldDefn("ID", OFTInteger);
if (layer1->CreateField(&fieldDefn) != OGRERR_NONE)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
for (int i = 0; i < latitudes.size()-1; ++i) {
OGRFeature* feature1 = OGRFeature::CreateFeature(layer1->GetLayerDefn());
feature1->SetField("ID", i + 1);
OGRPoint point(longitudes[i], latitudes[i]);
OGRLineString line;
line.addPoint(longitudes[i], latitudes[i]);
line.addPoint(longitudes[i + 1], latitudes[i + 1]);
feature1->SetGeometry(&line);
if (layer1->CreateFeature(feature1) != OGRERR_NONE)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
OGRFeature::DestroyFeature(feature1);
}
//GDALClose(dataset);
//std::cout << " Line Shapefile created: " << filename << std::endl;
return dataset;
}
int main() {
OGRRegisterAll();
const char* driverName = "ESRI Shapefile";
GDALDriver* driver = GetGDALDriverManager()->GetDriverByName(driverName);
if (driver == nullptr)
{
printf("%s driver not available.\n", driverName);
exit(1);
}
std::string op = "one.shp";
GDALDataset* dataset = driver->Create(op.c_str(), 0, 0, 0, GDT_Unknown, nullptr);
if (dataset == nullptr)
{
printf("%s driver not available.\n");
exit(1);
}
std::string filename = "test.csv";
std::ifstream file(filename);
if (!file)
{
std::cerr << "Failed to open file: " << filename << std::endl;
return 1;
}
std::vector<double> latitudes;
std::vector<double> longitudes;
std::string line;
while (std::getline(file, line))
{
std::istringstream iss(line);
std::string lat, lon;
if (std::getline(iss, lat, ',') && std::getline(iss, lon, ','))
{
double latitude = std::stod(lat);
double longitude = std::stod(lon);
latitudes.push_back(latitude);
longitudes.push_back(longitude);
}
}
if (latitudes.empty() || longitudes.empty())
{
std::cerr << "No coordinates found in the file." << std::endl;
return 1;
}
//"D:\\BetaProj\\BetaProj\\coordinates.csv"; // CSV file containing latitude and longitude
coordinates
dataset = createLineShapefile(op, latitudes, longitudes, dataset);
//dataset = driver->Create(op.c_str(), 0, 0, 0, GDT_Unknown, nullptr);
dataset = createPointShapefile(op, latitudes, longitudes,dataset);
GDALClose(dataset);
std::cout << " Line Shapefile created: " << filename << std::endl;
return 0;
}
*/
//----------code 6---------------------------
/*
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
const double earthRadius = 6371.0; // Earth radius in kilometers
double dlat = (lat2 - lat1) * (M_PI / 180.0); double dlon = (lon2 - lon1) * (M_PI / 180.0);
double a = sin(dlat / 2.0) * sin(dlat / 2.0) + cos(lat1 * (M_PI / 180.0)) * cos(lat2 * (M_PI /
180.0)) * sin(dlon / 2.0) * sin(dlon / 2.0);
double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));
double distance = earthRadius * c;
return distance;
}
void createPointShapefile(const std::string& filename, const std::vector<double>& latitudes, const
std::vector<double>& longitudes)
{
OGRRegisterAll();
const char* driverName = "ESRI Shapefile";
GDALDriver* driver = GetGDALDriverManager()->GetDriverByName(driverName);
if (driver == nullptr)
{
printf("%s driver not available.\n", driverName);
exit(1);
}
GDALDataset* dataset = driver->Create(filename.c_str(), 0, 0, 0, GDT_Unknown, nullptr);
if (dataset == nullptr)
{
printf("%s driver not available.\n");
exit(1);
}
OGRSpatialReference srs;
srs.SetWellKnownGeogCS("WGS84");
OGRLayer* layer = dataset->CreateLayer("points", &srs, wkbPoint);
if (layer == nullptr)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
OGRFieldDefn fieldDefn("ID", OFTInteger);
if (layer->CreateField(&fieldDefn) != OGRERR_NONE)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
OGRFeature* feature = OGRFeature::CreateFeature(layer->GetLayerDefn());
for (int i = 0; i < latitudes.size(); ++i)
{
feature->SetField("ID", i+1);
OGRPoint point(longitudes[i], latitudes[i]);
feature->SetGeometry(&point);
std::cout << " Point created: " << i << std::endl;
if (layer->CreateFeature(feature) != OGRERR_NONE)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
}
OGRFeature::DestroyFeature(feature);
GDALClose(dataset);
std::cout << " Point Shapefile created: " << filename << std::endl;
}
void createLineShapefile(const std::string& filename, const std::vector<double>& latitudes, const
std::vector<double>& longitudes)
{
OGRRegisterAll();
const char* driverName = "ESRI Shapefile";
GDALDriver* driver = GetGDALDriverManager()->GetDriverByName(driverName);
if (driver == nullptr)
{
printf("%s driver not available.\n", driverName);
exit(1);
}
GDALDataset* dataset = driver->Create(filename.c_str(), 0, 0, 0, GDT_Unknown, nullptr);
if (dataset == nullptr)
{
printf("%s driver not available.\n");
exit(1);
}
OGRSpatialReference srs;
srs.SetWellKnownGeogCS("WGS84");
OGRLayer* layer = dataset->CreateLayer("lines", &srs, wkbLineString);
if (layer == nullptr)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
OGRFieldDefn fieldDefn("ID", OFTInteger);
if (layer->CreateField(&fieldDefn) != OGRERR_NONE)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
for (int i = 0; i < latitudes.size()-1; ++i) {
OGRFeature* feature = OGRFeature::CreateFeature(layer->GetLayerDefn());
feature->SetField("ID", i + 1);
OGRPoint point(longitudes[i], latitudes[i]);
OGRLineString line;
line.addPoint(longitudes[i], latitudes[i]);
line.addPoint(longitudes[i + 1], latitudes[i + 1]);
feature->SetGeometry(&line);
if (layer->CreateFeature(feature) != OGRERR_NONE)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
OGRFeature::DestroyFeature(feature);
}
GDALClose(dataset);
std::cout << " Line Shapefile created: " << filename << std::endl;
}
int main() {
GDALAllRegister();
std::string filename = "coordinates.csv"; //"D:\\BetaProj\\BetaProj\\coordinates.csv"; //
CSV file containing latitude and longitude coordinates
std::ifstream file(filename);
if (!file)
{
std::cerr << "Failed to open file: " << filename << std::endl;
return 1;
}
std::vector<double> latitudes;
std::vector<double> longitudes;
std::string line;
while (std::getline(file, line))
{
std::istringstream iss(line);
std::string lat, lon;
if (std::getline(iss, lat, ',') && std::getline(iss, lon, ','))
{
double latitude = std::stod(lat);
double longitude = std::stod(lon);
latitudes.push_back(latitude);
longitudes.push_back(longitude);
}
}
if (latitudes.empty() || longitudes.empty())
{
std::cerr << "No coordinates found in the file." << std::endl;
return 1;
}
std::cout << "Total coordinates: " << latitudes.size() << std::endl;
std::string outputFilename = "pointsss.shp";
createPointShapefile(outputFilename, latitudes, longitudes);
createLineShapefile(outputFilename, latitudes, longitudes);
return 0;
}*/
/*
#include <iostream>
#include <fstream>
#include <sstream>
#include "gdal.h"
void createPoint(double x, double y, OGRLayer* layer)
{
OGRFeatureDefn* featureDefn = layer->GetLayerDefn();
OGRFeature* feature = new OGRFeature(featureDefn);
OGRPoint point(x, y);
feature->SetGeometry(&point);
layer->CreateFeature(feature);
delete feature;
}
void createLine(double x1, double y1, double x2, double y2, OGRLayer* layer)
{
OGRFeatureDefn* featureDefn = layer->GetLayerDefn();
OGRFeature* feature = new OGRFeature(featureDefn);
OGRLineString line;
line.addPoint(x1, y1);
line.addPoint(x2, y2);
feature->SetGeometry(&line);
layer->CreateFeature(feature);
delete feature;
}
void findIntersection(OGRLineString* line1, OGRLineString* line2) {
OGRLineString intersection;
if (line1->Intersect(line2, &intersection))
{
OGRPoint* point = new OGRPoint();
if (intersection.getNumPoints() > 0) {
intersection.getStartPoint(point);
double x = point->getX();
double y = point->getY();
std::cout << "Intersection Point: (" << x << ", " << y << ")" << std::endl;
} delete point;
}
}
void processCSV(const char* filePath, char delimiter, int latCol, int longCol) {
std::ifstream file(filePath); std::string line;
OGRRegisterAll();
OGRSpatialReference srs; srs.SetWellKnownGeogCS("WGS84");
OGRDataSource* dataSource = OGRSFDriverRegistrar::GetRegistrar()-
>CreateDataSource("output.shp", nullptr);
OGRLayer* pointLayer = dataSource->CreateLayer("Points", &srs, wkbPoint, nullptr);
pointLayer->CreateField(new OGRFieldDefn("Latitude", OFTReal));
pointLayer->CreateField(new OGRFieldDefn("Longitude", OFTReal));
OGRLayer* lineLayer = dataSource->CreateLayer("Lines", &srs, wkbLineString, nullptr);
OGRLineString* prevLine = nullptr;
while (std::getline(file, line)) {
std::istringstream iss(line); std::string token;
int colIndex = 0;
double latitude, longitude;
while (std::getline(iss, token, delimiter)) {
if (colIndex == latCol) latitude = std::stod(token);
else if (colIndex == longCol) longitude = std::stod(token);
colIndex++;
}
createPoint(latitude, longitude, pointLayer);
if (prevLine != nullptr) {
double prevX1, prevY1, prevX2, prevY2;
prevLine->getPoint(1, &prevX2, &prevY2);
createLine(prevX1, prevY1, latitude, longitude, lineLayer);
findIntersection(prevLine, lineLayer->GetFeature(lineLayer-
>GetFeatureCount() 1)->GetGeometryRef()->toLineString());
}
prevLine = new OGRLineString();
prevLine->addPoint(latitude, longitude);
}
delete prevLine;
OGRDataSource::DestroyDataSource(dataSource);
}
int main() {
const char* filePath = "data.csv";
char delimiter = ',';
int latCol = 0; // Latitude column index (0-based)
int longCol = 1; // Longitude column index (0-based)
processCSV(filePath, delimiter, latCol, longCol);
return 0;
}*/
//------------------------code 7--------start-----------------start--------------------start----------
//-------trying to do line using bearing and angle and distance------------------------------
/*
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "ogr_geometry.h"
#include "ogr_feature.h"
#include "ogr_core.h"
#include<cmath>
double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
const double earthRadius = 6371.0; // Earth radius in kilometers
double dlat = (lat2 - lat1) * (M_PI / 180.0); double dlon = (lon2 - lon1) * (M_PI / 180.0);
double a = sin(dlat / 2.0) * sin(dlat / 2.0) + cos(lat1 * (M_PI / 180.0)) * cos(lat2 * (M_PI /
180.0)) * sin(dlon / 2.0) * sin(dlon / 2.0);
double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));
double distance = earthRadius * c;
return distance;
}
GDALDataset* createPointShapefile(const std::string& filename, const std::vector<double>&
latitudes, const std::vector<double>& longitudes, GDALDataset* dataset)
{
OGRSpatialReference srs;
srs.SetWellKnownGeogCS("WGS84");
OGRLayer* layer = dataset->CreateLayer("points", &srs, wkbPoint);
if (layer == nullptr)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
OGRFieldDefn fieldDefn("ID", OFTInteger);
if (layer->CreateField(&fieldDefn) != OGRERR_NONE)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
OGRFeature* feature = OGRFeature::CreateFeature(layer->GetLayerDefn());
for (int i = 0; i < latitudes.size(); ++i)
{
feature->SetField("ID", i + 1);
OGRPoint point(longitudes[i], latitudes[i]);
feature->SetGeometry(&point);
std::cout << " Point created: " << i << std::endl;
if (layer->CreateFeature(feature) != OGRERR_NONE)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
}
OGRFeature::DestroyFeature(feature);
//GDALClose(dataset);
//std::cout << " Point Shapefile created: " << filename << std::endl;
return dataset;
}
GDALDataset* createLineShapefile(const std::string& filename, const std::vector<double>&
latitudes, const std::vector<double>& longitudes, GDALDataset* dataset)
{
OGRSpatialReference srs;
srs.SetWellKnownGeogCS("WGS84");
OGRLayer* layer1 = dataset->CreateLayer("lines", &srs, wkbMultiLineString);
if (layer1 == nullptr)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
OGRFieldDefn fieldDefn("ID", OFTInteger);
if (layer1->CreateField(&fieldDefn) != OGRERR_NONE)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
for (int i = 0; i < latitudes.size(); ++i) {
OGRFeature* feature1 = OGRFeature::CreateFeature(layer1->GetLayerDefn());
feature1->SetField("ID", i + 1);
OGRPoint point(longitudes[i], latitudes[i]);
OGRLineString line;
line.addPoint(longitudes[i], latitudes[i]);
line.addPoint(longitudes[i + 1], latitudes[i + 1]);
const double earthRadius = 6371.0; // Earth radius in kilometers
double angle = 45.0; // Angle in degrees
double distance = 200.0; // Distance in meters
// Convert the angle to
radians
double angleRad = angle * (M_PI / 180.0);
int bearing = 90;
// Calculate the end point coordinates
double startX = longitudes[i] * (M_PI / 180.0);
double startY = latitudes[i] * (M_PI / 180.0);
double a = bearing* (M_PI / 180.0);
double endY = (asin(sin(startY) * cos(distance / earthRadius) + cos(startY) *
sin(distance / earthRadius) * cos(a)))*180/ M_PI;
double endX = (startX + atan2(sin(a) * sin(distance / earthRadius) * cos(startY),
cos(distance / earthRadius) - sin(startY) * sin(endY))) * 180 / M_PI;
std::cout << endX << " " << endY;
// Add the start and end points to the line geometry
line.addPoint(startX, startY);
line.addPoint(endX, endY);
feature1->SetGeometry(&line);
if (layer1->CreateFeature(feature1) != OGRERR_NONE)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
OGRFeature::DestroyFeature(feature1);
}
//GDALClose(dataset);
//std::cout << " Line Shapefile created: " << filename << std::endl;
return dataset;
}
int main() {
OGRRegisterAll();
const char* driverName = "ESRI Shapefile";
GDALDriver* driver = GetGDALDriverManager()->GetDriverByName(driverName);
if (driver == nullptr)
{
printf("%s driver not available.\n", driverName);
exit(1);
}
std::string op = "one.shp";
GDALDataset* dataset = driver->Create(op.c_str(), 0, 0, 0, GDT_Unknown, nullptr);
if (dataset == nullptr)
{
printf("%s driver not available.\n");
exit(1);
}
std::string filename = "abcd.csv";
std::ifstream file(filename);
if (!file)
{
std::cerr << "Failed to open file: " << filename << std::endl;
return 1;
}
std::vector<double> latitudes;
std::vector<double> longitudes;
std::string line;
while (std::getline(file, line))
{
std::istringstream iss(line);
std::string lat, lon;
if (std::getline(iss, lat, ',') && std::getline(iss, lon, ','))
{
double latitude = std::stod(lat);
double longitude = std::stod(lon);
latitudes.push_back(latitude);
longitudes.push_back(longitude);
}
}
if (latitudes.empty() || longitudes.empty())
{
std::cerr << "No coordinates found in the file." << std::endl;
return 1;
}
//"D:\\BetaProj\\BetaProj\\coordinates.csv"; // CSV file containing latitude and longitude
coordinates
dataset = createLineShapefile(op, latitudes, longitudes, dataset);
//dataset = driver->Create(op.c_str(), 0, 0, 0, GDT_Unknown, nullptr);
dataset = createPointShapefile(op, latitudes, longitudes, dataset);
GDALClose(dataset);
std::cout << " Line Shapefile created: " << filename << std::endl;
return 0;
}*/
/*
int main() { // Initialize GDAL GDALAllRegister();
// Create a new shapefile
const char* shapefile = "line.shp"; GDALDriver* driver = GetGDALDriverManager()-
>GetDriverByName("ESRI Shapefile"); GDALDataset* dataset = driver->Create(shapefile, 0, 0, 0,
GDT_Unknown, nullptr);
// Create a new layer
OGRSpatialReference srs;
srs.SetWellKnownGeogCS("WGS84");
OGRLayer* layer = dataset->CreateLayer("lines", &srs, wkbMultiLineString);
if (layer == nullptr)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
OGRFieldDefn fieldDefn("ID", OFTInteger);
if (layer->CreateField(&fieldDefn) != OGRERR_NONE)
{
printf("%s driver not available.\n");
GDALClose(dataset);
exit(1);
}
// Create a line geometry OGRLineString line;
// Specify the starting point coordinates (longitude, latitude)
double startLon = -123.456789; double startLat = 45.678901;
// Specify the angle and distance (400 km)
double angle = 45.0; // Angle in degrees
double distance = 400000.0; // Distance in meters
// Convert the angle to radians
double angleRad = angle * (M_PI / 180.0);
// Calculate the end point coordinates
double startX = startLon;
double startY = startLat;
double endX = startX + (distance * std::cos(angleRad));
double endY = startY + (distance * std::sin(angleRad));
// Add the start and end points to the line geometry
OGRLineString line;
line.addPoint(startX, startY); line.addPoint(endX, endY);
// Create a new feature and set the geometry
OGRFeature* feature = OGRFeature::CreateFeature(layer->GetLayerDefn()); feature-
>SetGeometry(&line);
// Add the feature to the layer
layer->CreateFeature(feature);
// Clean up
OGRFeature::DestroyFeature(feature); GDALClose(dataset);
return 0;
}*/
//-------------new code--------------------------
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "ogr_geometry.h"
#include "ogr_feature.h"
#include "ogr_core.h"
//commented header file
double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
	const double earthRadius = 6371.0; // Earth radius in kilometers
	double dlat = (lat2 - lat1) * (M_PI / 180.0); double dlon = (lon2 - lon1) * (M_PI / 180.0);
	double a = sin(dlat / 2.0) * sin(dlat / 2.0) + cos(lat1 * (M_PI / 180.0)) * cos(lat2 * (M_PI /
		180.0)) * sin(dlon / 2.0) * sin(dlon / 2.0);
	double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));
	double distance = earthRadius * c;
	return distance;
}
GDALDataset* createPointShapefile(const std::string& filename, const std::vector<double>&
	latitudes, const std::vector<double>& longitudes, GDALDataset* dataset)
{
	OGRSpatialReference srs;
	srs.SetWellKnownGeogCS("WGS84");
	OGRLayer* layer = dataset->CreateLayer("points", &srs, wkbPoint);
	if (layer == nullptr)
	{
		printf("%s driver not available.\n");
		GDALClose(dataset);
		exit(1);
	}
	OGRFieldDefn fieldDefn("ID", OFTInteger);
	if (layer->CreateField(&fieldDefn) != OGRERR_NONE)
	{
		printf("%s driver not available.\n");
		GDALClose(dataset);
		exit(1);
	}
	OGRFeature* feature = OGRFeature::CreateFeature(layer->GetLayerDefn());
	for (int i = 0; i < latitudes.size(); ++i)
	{
		feature->SetField("ID", i + 1);
		OGRPoint point(longitudes[i], latitudes[i]);
		feature->SetGeometry(&point);
		std::cout << " Point created: " << i << std::endl;
		if (layer->CreateFeature(feature) != OGRERR_NONE)
		{
			printf("%s driver not available.\n");
			GDALClose(dataset);
			exit(1);
		}
	}
	OGRFeature::DestroyFeature(feature);
	//GDALClose(dataset);
	//std::cout << " Point Shapefile created: " << filename << std::endl;
	return dataset;
}
GDALDataset* createLineShapefile(const std::string& filename, const std::vector<double>&
	latitudes, const std::vector<double>& longitudes, GDALDataset* dataset)
{
	OGRSpatialReference srs;
	srs.SetWellKnownGeogCS("WGS84");
	OGRLayer* layer1 = dataset->CreateLayer("lines", &srs, wkbMultiLineString);
	if (layer1 == nullptr)
	{
		printf("%s driver not available.\n");
		GDALClose(dataset);
		exit(1);
	}
	OGRFieldDefn fieldDefn("ID", OFTInteger);
	if (layer1->CreateField(&fieldDefn) != OGRERR_NONE)
	{
		printf("%s driver not available.\n");
		GDALClose(dataset);
		exit(1);
	}
	for (int i = 0; i < latitudes.size() - 1; ++i) {
		OGRFeature* feature1 = OGRFeature::CreateFeature(layer1->GetLayerDefn());
		feature1->SetField("ID", i + 1);
		OGRPoint point(longitudes[i], latitudes[i]);
		OGRLineString line;
		line.addPoint(longitudes[i], latitudes[i]);
		line.addPoint(longitudes[i + 1], latitudes[i + 1]);
		feature1->SetGeometry(&line);
		if (layer1->CreateFeature(feature1) != OGRERR_NONE)
		{
			printf("%s driver not available.\n");
			GDALClose(dataset);
			exit(1);
		}
		OGRFeature::DestroyFeature(feature1);
	}
	//GDALClose(dataset);
	//std::cout << " Line Shapefile created: " << filename << std::endl;
	return dataset;
}
int main() {
	OGRRegisterAll();
	const char* driverName = "ESRI Shapefile";
	GDALDriver* driver = GetGDALDriverManager()->GetDriverByName(driverName);
	if (driver == nullptr)
	{
		printf("%s driver not available.\n", driverName);
		exit(1);
	}
	std::string op = "one.shp";
	GDALDataset* dataset = driver->Create(op.c_str(), 0, 0, 0, GDT_Unknown, nullptr);
	if (dataset == nullptr)
	{
		printf("%s driver not available.\n");
		exit(1);
	}
	std::string filename = "test.csv";
	std::ifstream file(filename);
	if (!file)
	{
		std::cerr << "Failed to open file: " << filename << std::endl;
		return 1;
	}
	std::vector<double> latitudes;
	std::vector<double> longitudes;
	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string lat, lon;
		if (std::getline(iss, lat, ',') && std::getline(iss, lon, ','))
		{
			double latitude = std::stod(lat);
			double longitude = std::stod(lon);
			latitudes.push_back(latitude);
			longitudes.push_back(longitude);
		}
	}
	if (latitudes.empty() || longitudes.empty())
	{
		std::cerr << "No coordinates found in the file." << std::endl;
		return 1;
	}
	//"D:\\BetaProj\\BetaProj\\coordinates.csv"; // CSV file containing latitude and longitude coordinates
		dataset = createLineShapefile(op, latitudes, longitudes, dataset);
	//dataset = driver->Create(op.c_str(), 0, 0, 0, GDT_Unknown, nullptr);
	dataset = createPointShapefile(op, latitudes, longitudes, dataset);
	GDALClose(dataset);
	std::cout << " Line Shapefile created: " << filename << std::endl;
	return 0;
}