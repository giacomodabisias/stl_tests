#include <iostream>
#include <vector>
#include <queue>

struct comparator{
    bool operator() ( int i, int j){
        return i > j;
    }
};

class Graph{
	
public:
	std::vector<std::vector<bool>> vertexes;
	int size;

	Graph(int size): size(size), vertexes(size, std::vector<bool>(size)){
	}

	void add_edge(int i, int j){
		vertexes[i][j] = true;
	}

	void dfs(int i){
		std::vector<bool> visited(size, false);
		dfs_(i, visited);
	}

	void bfs(int i){

		std::priority_queue<int, std::vector<int>, comparator> minHeap;
		std::vector<bool> visited(size, false);
		minHeap.push(0);
		bfs_(minHeap, visited);
	}

private:
	void dfs_(int i, std::vector<bool> & visited){

		visited[i] = true;
		for(int j = 0; j < size ; ++j){
			if(vertexes[i][j] == true && !visited[j]){
				std::cout << "visiting " << j << std::endl;
				dfs_(j, visited);
			}
		}	

	}

	void bfs_(std::priority_queue<int, std::vector<int>, comparator> & minHeap, std::vector<bool> & visited){

		while(!minHeap.empty()){
			int i = minHeap.top();
			minHeap.pop();
			for(int j = 0; j < size ; ++j){
				if(vertexes[i][j] == true && !visited[j]){
					std::cout << "visiting " << j << std::endl;
					minHeap.push(j);
					visited[j] = true;
				}
				
			}
		}	

	}
};

int main (int argc, char * argv[]){
	

	Graph g(8);
	g.add_edge(0,1);
	g.add_edge(0,2);
	g.add_edge(1,4);
	g.add_edge(2,3);
	g.add_edge(4,5);
	g.add_edge(3,5);
	g.add_edge(1,7);
	g.add_edge(2,6);
	std::cout << "dfs" << std::endl;
	g.dfs(0);
	std::cout << "bfs" << std::endl;
	g.bfs(0);

}