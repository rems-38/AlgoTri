#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fonctions.h"


void affiche(int *a, int n){
	int i;
	for (i = 0 ; i < n ; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

int compare(int *a, int *b, int n){
	int i;
	for(i=0; i < n ; i++){
		if (a[i] != b[i]){
			printf("Comparison FAILED at index %d\n", i);
			return i;
		}
	}
	printf("Comparison OK\n");
	return -1;	
}

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int tri_bulle(int *a, int n){
	int swap_number = 0;
	int i, j;
	bool trie;
	for (i = 0 ; i < n - 1 ; i++){
		trie = true;
		for (j = 0 ; j < n - i - 1 ; j++){
			if (a[j] > a[j+1]){
				swap(&a[j], &a[j+1]);
				swap_number++;
				trie = false;
			}
		}
		if (trie){
			break;
		}
	}
	return swap_number;
}

int tri_insertion(int *a, int n){
	int swap_number = 0;
	int i, j;
	for (i = 1 ; i < n ; i++){
		for (j = i ; j > 0 ; j--){
			if (a[j] < a[j-1]){
				swap(&a[j], &a[j-1]);
				swap_number++;
			}
		}
	}
	return swap_number;
}

int tri_merge(int *a, int n) {
	int swap_number = 0;
	int *tmp = malloc(n * sizeof(int));

	merge_aux(a, tmp, 0, n, &swap_number);
	
	for(int i = 0; i < n; i++) {
		a[i] = tmp[i];
	}
	free(tmp);

	return swap_number;
}

void merge_aux(int *tab, int *tmp, int left, int right, int *cnt) {
	int delta = right - left;
	int mid = ((right + left) / 2) + 1;
	
	if(delta <= 1) return;
	else {
		merge_aux(tab, tmp, left, mid - 1, cnt);
		merge_aux(tab, tmp, mid, right, cnt);
		merge(tab, tmp, left, mid, delta, cnt);
	}
	return;
}


void merge (int *tab, int *tmp, int left, int mid, int right, int *cnt) {
	int init_mid = mid;
	bool end_left = false, end_mid = false;
	for(int i = left; i < right; i++) {
		if(!end_left && !end_mid) {
			if(tab[left] < tab[mid]) {
				tmp[i] = tab[left];
				if(left < init_mid - 1) {
					left++;
				}
				else {
					end_left = true;
				}
			}
			else {
				tmp[i] = tab[mid];
				if(mid < right - 1) {
					mid++;
				}
				else {
					end_mid = true;
				}
			}
		}
		else if(end_left) {
			tmp[i] = tab[mid];
			if(mid < right - 1) {
				mid++;
			}
			else {
				end_mid = true;
			}
		}
		else if(end_mid) {
			tmp[i] = tab[left];
			if(left < init_mid - 1) {
				left++;
			}
			else {
				end_left = true;
			}
		}
	}
}