#ifndef APPLICANT_H
#define APPLICANT_H

struct Applicant
{
    int workerID;

    double workerLatitude;
    double workerLongitude;

    double workerRating;

    double distance;

    long long applicationTime;

    Applicant *next;
};

#endif