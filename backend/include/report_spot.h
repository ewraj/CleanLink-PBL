#ifndef REPORT_SPOT_H
#define REPORT_SPOT_H

#include "waste_spot.h"

class ReportSpot {
public:
    void reportSpot(
        int reporterID,
        double latitude,
        double longitude,
        const char photoPath[],
        const char wasteType[],
        WasteSize estimatedSize
    );
};

#endif