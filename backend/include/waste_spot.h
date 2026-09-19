#ifndef WASTE_SPOT_H
#define WASTE_SPOT_H

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

typedef struct WasteSpot {
    int spotID;
    int reporterID;          // User who reported the spot

    double latitude;
    double longitude;

    char photoPath[200];
    char wasteType[50];

    WasteSize estimatedSize;
    int workerLimit;

    SpotStatus status;

    struct WasteSpot *next;  // Linked list pointer
} WasteSpot;

#endif