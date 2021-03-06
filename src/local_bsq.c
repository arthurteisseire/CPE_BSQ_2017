/*
** EPITECH PROJECT, 2017
** File Name : local_bsq.c
** File description:
** By Arthur Teisseire
*/

#include "bsq.h"

void local_bsq(bsq_t *bsq, int row, int col)
{
	int size_y = bsq->nb_col;
	int size_x = bsq->nb_row;
	int x = row;
	int y = col;

	while (x < bsq->nb_row && bsq->map[x][y] != 'o') {
		while (bsq->map[x][y] == '.')
			y++;
		if (y - col < bsq->size)
			return;
		if (y - col < size_y)
			size_y = y - col;
		size_x = x - (row - 1);
		if (size_x > bsq->size && size_y > bsq->size) {
			bsq->size = (size_y < size_x ? size_y : size_x);
			set_pos(&bsq->pos, row, col);
		}
		x++;
		y = col;
	}
}

void set_pos(pos_t *pos, int row, int col)
{
	pos->x = row;
	pos->y = col;
}
