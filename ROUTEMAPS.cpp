#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "Route.h"
using namespace std;

int main() {
	//
	typedef std::vector<Location> MyLocations;
	typedef std::vector<Road> MyRoads;
	typedef std::vector<Route> MyRoutes;

	MyLocations locations;
	MyRoads roads;
	MyRoutes routes;

	std::string space_string, textline = "";

	int locationNo, roadNo, routeNo, lineCtr=0, a=0;
	int noLocations, noRoads, noRoutes;

	ifstream infile;
	infile.open("route-maps-input.txt");
	//Reading input text file containing the data
	while (getline(infile, textline)) {
		std::istringstream text_stream(textline);		
		if (lineCtr == 0) { //reading the first line for no. Locations
			text_stream >> noLocations;
			locationNo = 0;
		}
		else if (lineCtr <= noLocations) { //reading the lines containing locations' details
			Location location;

			string locationNameInput;
			float xValueInput;
			float yValueInput;

			text_stream >> xValueInput; 
			getline(text_stream, space_string, ' ');
			text_stream >> yValueInput; 
			getline(text_stream, space_string, ' ');				
			getline(text_stream, locationNameInput);

			location.Location::setLocationName(locationNameInput);
			location.Location::setXValue(xValueInput);
			location.Location::setYValue(yValueInput);

			locations.push_back(location);			

			locationNo++;
		}
		else if (lineCtr == (noLocations+1)) { //reading the line containing no. Roads
			text_stream >> noRoads;
			roadNo = 0;
		}
		else if (lineCtr <= (noLocations + noRoads + 1)) {//reading the lines containing Roads' information
			Road road;

			int startPointIndex;
			int endPointIndex;
			std::string roadName;
			float widthRoad;

			text_stream >> startPointIndex; 
			getline(text_stream, space_string, ' ');
			text_stream >> endPointIndex; 
			getline(text_stream, space_string, ' ');
			getline(text_stream, roadName, ' ');
			text_stream >> widthRoad;

			road.Road::setStartLocation((locations[startPointIndex]));
			road.Road::setEndLocation((locations[endPointIndex]));
			road.Road::setRoadName(roadName);
			road.Road::setRoadWidth(widthRoad);

			roads.push_back(road);

			roadNo++;
		}
		else if (lineCtr == (noLocations + noRoads + 2)) { //reading the line containing no. Routes
			text_stream >> noRoutes;
			routeNo = 0;
		}		
		else { // reading the lines containing Routes' information
			int noRoadsInRoute;
			text_stream >> noRoadsInRoute;
			Route route;			
			MyRoads roadsForRoute;
			for (int roadNoInRoute = 0; roadNoInRoute < noRoadsInRoute; roadNoInRoute++) {
				int roadIndex;
				text_stream >> roadIndex;
				roadsForRoute.push_back(roads[roadIndex]);
			}
			route.setRoadsGrouping(roadsForRoute);			
			routes.push_back(route);
			routeNo++;
		}		
		lineCtr++;
	}

	for (size_t routeNo = 0; routeNo < routes.size(); routeNo++) {	//finding the route and length for each of the route and displaying
		cout<< "Route " << routeNo+1 <<": Length "<< routes[routeNo].Route::getLength() << ": ";
		for (size_t roadNo = 0; roadNo < routes[routeNo].Route::getRoadsGrouping().size(); roadNo++) {
			std::string roadName = routes[routeNo].Route::getRoadsGrouping()[roadNo].Road::getRoadName();
			std::string endPointName = routes[routeNo].Route::getRoadsGrouping()[roadNo].Road::getEndLocation().Location::getLocationName();
			if (roadNo == 0) {
				std::string startPointName = routes[routeNo].Route::getRoadsGrouping()[roadNo].Road::getStartLocation().Location::getLocationName();
				cout << "Start at " << startPointName ;
			}
			cout << ". Follow " << roadName << " to " << endPointName;
		}
		cout << "." << endl << endl;
	}
	return 0;
}
