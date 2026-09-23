#include "report_spot.h"
#include <cstring>

// Report a new waste spot
void ReportSpot::reportSpot(
    int reporterID,
    double latitude,
    double longitude,
    const char photoPath[],
    const char wasteType[],
    WasteSize estimatedSize
)
{
    WasteSpot spot;

    // Store basic spot information
    spot.reporterID = reporterID;
    spot.latitude = latitude;
    spot.longitude = longitude;

    strcpy(spot.photoPath, photoPath);
    strcpy(spot.wasteType, wasteType);

    // Store estimated size and initial status
    spot.estimatedSize = estimatedSize;
    spot.status = PENDING;

    // Initialize linked list of waste spots
    spot.next = NULL;

    // Initialize Applicant Linked List
    spot.applicantHead = NULL;

    // Initialize assigned workers
    spot.assignedCount = 0;

    // Assign initial worker limit according to waste size
    if (estimatedSize == SMALL)
    {
        spot.workerLimit = 2;
    }
    else if (estimatedSize == MEDIUM)
    {
        spot.workerLimit = 5;
    }
    else
    {
        spot.workerLimit = 10;
    }
}