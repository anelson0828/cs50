// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int x = fraction[0] - '0';
    int y = fraction[2] - '0';
    int duration = (8 / y) * x;
    return duration;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int freqvalue = 440; // A4 equals 440 Hz
    char baseletter = note[0];
    int semitones = 0;
    int octave = 4;
    bool isFlat = false;
    bool isSharp = false;
    char accidental = note[1];

    // see if note has a sharp or flat, and based on the length of the note, find the octave

    if (accidental == '#')
    {
        isSharp = true;
        octave = note[2];
    }
    else if (accidental == 'b')
    {
        isFlat = true;
        octave = note[2];
    }
    else
    {
        octave = note[1];
    }

    octave -= 48; //adjust ASCII to Int value

    // use the baseletter, sharp/flat, and octave to calculate the semitone distance

    switch (baseletter)
    {
        case 'A':
            // same as baseletter - do nothing
            break;
        case 'B':
            semitones = semitones + 2;
            break;
        case 'C':
            semitones = semitones - 9;
            break;
        case 'D':
            semitones = semitones - 7;
            break;
        case 'E':
            semitones = semitones - 5;
            break;
        case 'F':
            semitones = semitones - 4;
            break;
        case 'G':
            semitones = semitones - 2;
            break;
    }

    //adjust for sharps and flats
    if (isSharp)
    {
        semitones++;
    }
    if (isFlat)
    {
        semitones--;
    }

    //adjust for octave
    semitones = semitones + ((octave - 4) * 12);

    //calculate frequency

    double freq = 440 * pow(2.0, (semitones / 12.0));
    freqvalue = (int) round(freq);
    return freqvalue;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strlen(s) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}