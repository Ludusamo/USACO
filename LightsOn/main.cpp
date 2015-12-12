#include <stdio.h>
#include <utility>
#include <vector>

#define x first
#define y second
#define pb push_back

typedef std::pair<int, int> Point;
typedef std::vector<Point> VP;

typedef struct {
	bool lit;
	bool visited;
	VP switches;
} Room;

typedef std::vector< std::vector<Room> > Map;

int N, M;
Map rooms;
int num_lit;

bool has_lit_visited(int x, int y) {
	if (y > 0 && rooms[y - 1][x].lit)
		if (rooms[y - 1][x].visited)
			return true;
	if (y < N - 1 && rooms[y + 1][x].lit)
		if (rooms[y + 1][x].visited)
			return true;
	if (x > 0 && rooms[y][x - 1].lit)
		if (rooms[y][x - 1].visited)
			return true;
	if (x < N - 1 && rooms[y][x + 1].lit)
		if (rooms[y][x + 1].visited)
			return true;
	return false;
}

void visit_room(int x, int y) {
	Room &room = rooms[y][x];
	room.visited = true;
	printf("Visiting: %d, %d\n", x, y);

	if (y > 0 && rooms[y - 1][x].lit)
		if (!rooms[y - 1][x].visited)
			visit_room(x, y - 1);
	if (y < N - 1 && rooms[y + 1][x].lit)
		if (!rooms[y + 1][x].visited)
			visit_room(x, y + 1);
	if (x > 0 && rooms[y][x - 1].lit)
		if (!rooms[y][x - 1].visited)
			visit_room(x - 1, y);
	if (x < N - 1 && rooms[y][x + 1].lit)
		if (!rooms[y][x + 1].visited)
			visit_room(x + 1, y);

	for (int i = 0; i < room.switches.size(); i++) {
		Room &eval = rooms[room.switches[i].y][room.switches[i].x];
		if (!eval.lit) {
			num_lit++;
			eval.lit = true;
			if (!eval.visited) {
				if (has_lit_visited(room.switches[i].x, room.switches[i].y)) {
					visit_room(room.switches[i].x, room.switches[i].y);
				}
			}
		}
	}
}

int main() {
	num_lit = 1;

	FILE *in = fopen("lightson.in", "r");
	fscanf(in, "%d %d", &N, &M);
	printf("%d %d\n", N, M);

	for (int i = 0; i < N; i++) {
		Room r;
		r.lit = false;
		r.visited = false;
		std::vector<Room> room(N, r);
		rooms.pb(room);
	}
	rooms[0][0].lit = true;

	for (int i = 0; i < M; i++) {
		Point switchP;
		Point toggle;
		fscanf(in, "%d %d %d %d", &switchP.x, &switchP.y, &toggle.x, &toggle.y);
		toggle.x -= 1;
		toggle.y -= 1;
		rooms[switchP.y - 1][switchP.x - 1].switches.pb(toggle);
	}
	fclose(in);

	visit_room(0, 0);
	printf("%d\n", num_lit);

	FILE *out = fopen("lightson.out", "w");
	fprintf(out, "%d\n", num_lit);
	fclose(out);
		
	return 0;
}
