#ifndef WORKER_ASSIGNMENT_H
#define WORKER_ASSIGNMENT_H

#include "waste_spot.h"

double calculateDistance(
    double lat1,
    double lon1,
    double lat2,
    double lon2
);

void applyForSpot(
    WasteSpot *spot,
    int workerID,
    double workerLatitude,
    double workerLongitude,
    double workerRating
);

void displayApplicants(WasteSpot *spot);

void assignWorkers(WasteSpot *spot);

void displayAssignedWorkers(WasteSpot *spot);

#endif