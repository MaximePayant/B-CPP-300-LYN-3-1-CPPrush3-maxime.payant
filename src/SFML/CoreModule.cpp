/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** CoreModule.cpp
*/

#include "CoreModule.hpp"

sf::Sprite sfI::CoreModule::coreModule;

sf::Vector2f sfI::CoreModule::posList[12] = {{10, 350},
                                             {10, 449},
                                             {10, 548},
                                             {10, 647},
                                             {310, 350},
                                             {310, 449},
                                             {310, 548},
                                             {310, 647},
                                             {610, 350},
                                             {610, 449},
                                             {610, 548},
                                             {610, 647}};

sf::Vector2f sfI::CoreModule::barPosList[12] = {{52, 396},
                                                {52, 495},
                                                {52, 594},
                                                {52, 693},
                                                {353, 396},
                                                {353, 495},
                                                {353, 594},
                                                {353, 693},
                                                {654, 396},
                                                {654, 495},
                                                {654, 594},
                                                {654, 693}};

sf::Vector2f sfI::CoreModule::textPosList[12] = {{22, 360},
                                                 {22, 459},
                                                 {22, 558},
                                                 {22, 657},
                                                 {323, 360},
                                                 {323, 459},
                                                 {323, 558},
                                                 {323, 657},
                                                 {624, 360},
                                                 {624, 459},
                                                 {624, 558},
                                                 {624, 657}};


sfI::CoreModule::CoreModule(const sf::Vector2f& pos) :
_pos(pos)
{}

sfI::CoreModule::~CoreModule()
{}