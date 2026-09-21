#include "report_spot.h"
#include <cstring>











// input from user and storing into .dat file 


void ReportSpot::reportSpot(
    int reporterID,
    double latitude,
    double longitude,
    const char photoPath[],
    const char wasteType[],
    WasteSize estimatedSize
) {
  {
    WasteSpot spot;

    spot.reporterID = reporterID;
    spot.latitude = latitude;
    spot.longitude = longitude;

    strcpy(spot.photoPath, photoPath);
    strcpy(spot.wasteType, wasteType);

    spot.estimatedSize = estimatedSize;
    spot.status = PENDING;
    spot.next = NULL;

    // Assign initial worker limit
    if (estimatedSize == SMALL)
        spot.workerLimit = 2;
    else if (estimatedSize == MEDIUM)
        spot.workerLimit = 5;
    else
        spot.workerLimit = 10;   // Temporary value for large
}
}