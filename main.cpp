#include "coordinate.h"
#include <iostream> 
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits>

void add_coordinate(Coordinate *list_end, float x, float y)
{
	Coordinate* newCoordinate = new Coordinate;
	newCoordinate->x = x;
	newCoordinate->y = y;
	newCoordinate->coord_id = (list_end == NULL) ? 1 : list_end->coord_id + 1; ;
	newCoordinate->next = NULL;
	newCoordinate->previous = list_end;

		if (list_end != NULL) {
		list_end->next = newCoordinate;
		}
	}

void forward_display (Coordinate* list_beginning)
{

	Coordinate* current = list_beginning;
	std::cout << "forward: \n";

	while (current != NULL) {
		std::cout << " " << current->coord_id << "(" << current->x << "," << current->y << "}\n ";
		current = current->next;
		}
	}

void backward_display (Coordinate* list_end)
{
	Coordinate* current = list_end;
	std::cout << "backward: \n";

	while (current != NULL) {
		std::cout << " " << current->coord_id << "(" << current->x << "," << current->y << ")\n ";
		current = current->previous;
		}
	}

void delete_coordinate(Coordinate* list_beginning, int coord_to_delete) 
{
	Coordinate* current = list_beginning;
	while (current != NULL && current->coord_id != coord_to_delete) {
		current = current->next;
	}
	
	if (current->previous == NULL) {
		list_beginning = current->next;
	if (list_beginning != NULL) {
		list_beginning->previous = NULL;
	}
}
	else if (current->next == NULL) {
	current->previous->next = NULL;
	}
	
	else { 
	current->previous->next = current->next;
	current->next->previous = current->previous;
	}

std::cout << "Deleted Coordinate" << current->coord_id << "(" << current->x << ", " << current->y << ")\n";
delete current;
}
 
void closest_to(Coordinate *list_beginning, float x, float y) {
    Coordinate *current = list_beginning;
    Coordinate *closestCoordinate = NULL;
    double minDistance = std::numeric_limits<double>::max(); 

    while (current != NULL) {
	 double dist = std::sqrt(std::pow(current->x - x, 2) + std::pow(current->y - y, 2)); 
          if (dist < minDistance) {
              minDistance = dist;
              closestCoordinate = current;
          }
          current = current->next;
    }

    if (closestCoordinate != NULL) {
       std::cout << "Closest coordinate to (" << x << "," << y << "): (" << closestCoordinate->x << ", " << closestCoordinate->y << ")\n";
       std::cout << "Distance: " << minDistance << std::endl;
    }
}	

int list_length(Coordinate *list_beginning)
{
    int length = 0;
    Coordinate *current = list_beginning;

    while (current != NULL)
    {
         length++;
         current = current->next;
    } 
    return length;
}

int main (int argc, char* argv[]) { 

    int num_coordinates = atoi(argv[1]);
    int coord_to_delete;	
    int length;	 
    srand(static_cast<unsigned int>(time(0)));
	Coordinate* list_beginning = NULL;
	Coordinate* list_end = NULL;

	for (int i = 0; i < num_coordinates; i++) {
		float x = static_cast<float>(rand() % 100);
		float y = static_cast<float>(rand() % 100);	
	
	if(list_end == NULL) {
		list_beginning = new Coordinate;
		list_beginning->x = x;
		list_beginning->y = y;
		list_beginning->coord_id = 1;
		list_beginning->next = NULL;
		list_beginning->previous = NULL;
		list_end = list_beginning; 
	} else { 
		add_coordinate(list_end, x, y);
		list_end = list_end->next;
	}
	
 }

forward_display(list_beginning);
backward_display(list_end);

std::cout << "\nEnter coordinate to delete: ";
std::cin >> coord_to_delete;

delete_coordinate(list_beginning, coord_to_delete);
length=list_length(list_beginning);
std::cout << "Length: " << length << std::endl;

closest_to(list_beginning, 49, 13);
return 0;
}

