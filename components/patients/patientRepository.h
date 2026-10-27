#ifndef PATIENTREPOSITORY_H
#define PATIENTREPOSITORY_H
#include "patient.h"

class PatientRepository
{
public:
    int savePatient (const Patient & patient);
};

#endif // PATIENTREPOSITORY_H
