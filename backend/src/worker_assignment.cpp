#include "worker_assignment.h"
#include "priority_queue.h"

#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.14159265358979323846;

double toRadians(double degree)
{
    return degree * PI / 180.0;
}

double calculateDistance(
    double lat1,
    double lon1,
    double lat2,
    double lon2
)
{
    const double EARTH_RADIUS = 6371.0;

    double dLat = toRadians(lat2 - lat1);
    double dLon = toRadians(lon2 - lon1);

    double a =
        sin(dLat / 2) * sin(dLat / 2) +
        cos(toRadians(lat1)) *
        cos(toRadians(lat2)) *
        sin(dLon / 2) *
        sin(dLon / 2);

    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return EARTH_RADIUS * c;
}


void applyForSpot(
    WasteSpot *spot,
    int workerID,
    double workerLatitude,
    double workerLongitude,
    double workerRating
)
{
    if (spot == nullptr)
    {
        return;
    }

    Applicant *newApplicant = new Applicant;

    newApplicant->workerID = workerID;

    newApplicant->workerLatitude = workerLatitude;
    newApplicant->workerLongitude = workerLongitude;

    newApplicant->workerRating = workerRating;

    // Calculate distance between worker and waste spot
    newApplicant->distance = calculateDistance(
        spot->latitude,
        spot->longitude,
        workerLatitude,
        workerLongitude
    );

    // Simple increasing application time
    static long long applicationCounter = 1;

    newApplicant->applicationTime = applicationCounter++;

    // Insert at beginning of linked list
    newApplicant->next = spot->applicantHead;

    spot->applicantHead = newApplicant;

    cout << "Worker " << workerID
         << " applied for Spot " << spot->spotID << endl;

    cout << "Distance: "
         << newApplicant->distance
         << " km" << endl;
}


void displayApplicants(WasteSpot *spot)
{
    if (spot == nullptr)
    {
        return;
    }

    Applicant *current = spot->applicantHead;

    cout << "\n--- Applicant Linked List ---\n";

    if (current == nullptr)
    {
        cout << "No applicants.\n";
        return;
    }

    while (current != nullptr)
    {
        cout << "Worker ID: "
             << current->workerID << endl;

        cout << "Distance: "
             << current->distance
             << " km" << endl;

        cout << "Rating: "
             << current->workerRating << endl;

        cout << "Application Time: "
             << current->applicationTime << endl;

        cout << "------------------\n";

        current = current->next;
    }
}


void assignWorkers(WasteSpot *spot)
{
    if (spot == nullptr)
    {
        return;
    }

    PriorityQueue pq;

    Applicant *current = spot->applicantHead;

    // Put all applicants into priority queue
    while (current != nullptr)
    {
        pq.push(current);

        current = current->next;
    }

    spot->assignedCount = 0;

    cout << "\n--- Priority Queue Assignment ---\n";

    // Select workers according to priority
    while (!pq.isEmpty() &&
           spot->assignedCount < spot->workerLimit &&
           spot->assignedCount < MAX_ASSIGNED_WORKERS)
    {
        Applicant *selected = pq.pop();

        spot->assignedWorkers[spot->assignedCount] =
            selected->workerID;

        cout << "Selected Worker: "
             << selected->workerID << endl;

        cout << "Distance: "
             << selected->distance
             << " km" << endl;

        cout << "Rating: "
             << selected->workerRating << endl;

        cout << "------------------\n";

        spot->assignedCount++;
    }

    if (spot->assignedCount > 0)
    {
        spot->status = ASSIGNED;
    }
}


void displayAssignedWorkers(WasteSpot *spot)
{
    if (spot == nullptr)
    {
        return;
    }

    cout << "\n--- Assigned Workers ---\n";

    for (int i = 0; i < spot->assignedCount; i++)
    {
        cout << "Worker "
             << spot->assignedWorkers[i]
             << endl;
    }
}