#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>

#include "list.h"

struct boolAndMeetingPoint
{
	_Bool isHaveRing;
	Node meetingPoint;
};
typedef struct boolAndMeetingPoint* boP;

boP IsRingExistNFindMeetingPoint(Node head);

Node findRingHead(Node head);