#ifndef WASTE_SPOT_H
#define WASTE_SPOT_H

#include "applicant.h"

// Waste size
typedef enum {
    SMALL,
    MEDIUM,
    LARGE
} WasteSize;

// Spot status
typedef enum {
    PENDING,
    VERIFIED,
    FUNDED,
    ASSIGNED,
    COMPLETED
} SpotStatus;

#define MAX_ASSIGNED_WORKERS 20

typedef struct WasteSpot
{
    int spotID;
    int reporterID;

    double latitude;
    double longitude;

    char photoPath[200];
    char wasteType[50];

    WasteSize estimatedSize;
    int workerLimit;

    SpotStatus status;

    // Linked list of applicants
    Applicant *applicantHead;

    // Workers selected by priority queue
    int assignedWorkers[MAX_ASSIGNED_WORKERS];
    int assignedCount;

    // Linked list of waste spots
    struct WasteSpot *next;

} WasteSpot;

#endif