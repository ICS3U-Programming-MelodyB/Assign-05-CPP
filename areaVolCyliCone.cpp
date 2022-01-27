// Copyright (c) 2021 Melody Berhane All rights reserved.
//
// Created by: Melody Berhane
// Created on: Jan 26, 2021
// This program asks the user for the unit, radius and height 
// It then calculates and displays the surface area and
// volume of a cylinder and cone.
#include <iostream>
#include <cmath>
#include <iomanip>


// Function for area of a cylinder
float CalcAreaCylinder(float radius, float height) {
    float area1, area2, area3, area4, area5, area6, area;
    area1 = 2.0 * M_PI;
    area2 = radius * height;
    area3 = area1 + area2;
    area4 = 2.0 * M_PI;
    area5 = pow(radius, 2.0);
    area6 = area4 + area5;
    area = area3 + area6;
    return area;
}


// Function for volume of a cylinder
float CalcVolCylinder(float radius, float height) {
    float vol1, vol;
    vol1 = pow(radius, 2.0);
    vol = vol1 * M_PI * height;
    return vol;
}


// Function for area of a cone
float CalcAreaCone(float radius, float height) {
    float area1, area2, area;
    area1 = sqrt((pow(height, 2.0))+(pow(radius, 2.0)));
    area2 = radius + area1;
    area = M_PI * radius * area2;
    return area;
}


// Function for volume of a cone
float CalcVolCone(float radius, float height) {
    float vol1, vol;
    vol1 = height/3.0;
    vol = M_PI * (pow(radius, 2.0)) * vol1;
    return vol;
}


int main() {
    // get input from user
    std::cout << "Welcome! Today we will be finding the surface area";
    std::cout << "and volume of a cylinder and cone\n";
    std::cout << "" << std::endl;
    while (true) {
        std::cout << "----------------------------------------------------\n";
        std::cout << "" << std::endl;
        std::string units;
        std::cout << "Enter the units: ";
        std::cin >> units;
        std::string radiusUser;
        std::cout << "Enter the radius: ";
        std::cin >> radiusUser;
        try {
            float radiusUserFloat;
            radiusUserFloat = std::stoi(radiusUser);
            if (radiusUserFloat <= 0) {
                std::cout << "Please enter a number greater than 0!";
                std::cout << "" << std::endl;
                std::cout << "Please enter a valid height";
                continue;
            } else {
                std::string heightUser;
                std::cout << "Enter the height: ";
                std::cin >> heightUser;
                try {
                    // gets height from user
                    float heightUserFloat;
                    heightUserFloat = std::stoi(heightUser);
                    if (heightUserFloat <= 0) {
                        std::cout << "Please enter a number greater than 0!";
                        std::cout << "" << std::endl;
                        std::cout << "Please enter a valid height";
                        // goes back to the top of the while true loop
                        continue;
                    } else {
                        std::cout << "" << std::endl;
                        std::string question;
                        std::cout << "Would you like to find the surface area ";
                        std::cout << "and volume of a cylinder or cone?: ";
                        std::cin >> question;
                        if (question == "cone") {
                            float coneAreaUser, coneVolUser;
                            coneAreaUser = CalcAreaCone\
                                           (radiusUserFloat, heightUserFloat);
                            coneVolUser = CalcVolCone\
                                          (radiusUserFloat, heightUserFloat);
                            std::cout << "" << std::endl;
                            std::cout << "The surface of the cone is ";
                            std::cout << coneAreaUser << units << "\n";
                            std::cout << "The volume of the cone is ";
                            std::cout << coneVolUser << units;
                            std::cout << "" << std::endl;
                            std::string askAgain;
                            std::cout << "Would you like to play again(y/n)?: ";
                            std::cin >> askAgain;
                            if (askAgain == "yes" || askAgain == "y") {
                                // goes back to the top of the while true loop
                                continue;
                            } else {
                                std::cout << "Thank you for playing!";
                                // Ends the while true loop
                                break;
                            }
                        } else {
                            float cylinderAreaUser, cylinderVolUser;
                            cylinderAreaUser = CalcAreaCylinder\
                                               (radiusUserFloat, \
                                                heightUserFloat);
                            cylinderVolUser = CalcVolCylinder\
                                              (radiusUserFloat, \
                                                heightUserFloat);
                            std::cout << "" << std::endl;
                            std::cout << "The surface of the cylinder is ";
                            std::cout << cylinderAreaUser << units << "\n";
                            std::cout << "The volume of the cylinder is ";
                            std::cout << cylinderVolUser << units << "\n";
                            std::cout << "" << std::endl;
                            std::string askAgain;
                            std::cout << "Would you like to play again(y/n)?: ";
                            std::cin >> askAgain;
                            if (askAgain == "yes" || askAgain == "y") {
                                // goes back to the top of the while true loop
                                continue;
                            } else {
                                std::cout << "Thank you for playing!";
                                // Ends the while true loop
                                break;
                            }
                        }
                    }
                } catch (std::invalid_argument) {
                    // The user did not enter a number.
                    std::cout << heightUser << " is not a number.\n";
                    std::cout << std::endl;
                    std::cout << "Please enter a valid radius.\n";
                    // goes back to the top of the while true loop
                    continue;
                }
            }
        } catch (std::invalid_argument) {
            // The user did not enter a number.
            std::cout << radiusUser << " is not a number.\n";
            std::cout << std::endl;
            std::cout << "Please enter a valid radius.\n";
            // goes back to the top of the while true loop
            continue;
        }
    }
}
