#pragma once
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<time.h>
#include<fstream>
#define M 10000
#define N 50000
#define K 200000
void Menu();
void menu();
void time1(int*, int);
void time2(int*, int, int);
void swap(int* a, int* b);
void InsertSort(int par_array[], int array_size);
void MergeSort(int arr[], int n);
void msort(int arr[], int tempArr[], int left, int right);
void merge(int arr[], int tempArr[], int left, int mid, int right);
void QuickSort(int arr[], int left, int right);
void CountSort(int* arr, int length);
void RadixSort(int* arr, int length);
void putout(int len, int max);
void putin(int len, int op_1);