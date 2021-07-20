#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using std::vector;
using std::cin;
using std::cout;
using std::priority_queue;
using std::pair;

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    vector<long long> next_free_time(num_workers_, 0);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, std::greater<pair<long long, long long>>> pq;
    for (size_t j = 0; j < num_workers_; ++j) {
          pq.push({0, j});
    }
    for (size_t i = 0; i < jobs_.size(); ++i) {
      long long duration = jobs_[i];
      auto next_worker = pq.top();
      assigned_workers_[i] = next_worker.second;
      start_times_[i] = next_worker.first;
      pq.pop();
      pq.push({next_worker.first + duration, next_worker.second});
    }

    // for (int i = 0; i < jobs_.size(); ++i) {
    //   int duration = jobs_[i];
    //   int next_worker = 0;
    //   for (int j = 0; j < num_workers_; ++j) {
    //     if (next_free_time[j] < next_free_time[next_worker])
    //       next_worker = j;
    //   }
    //   assigned_workers_[i] = next_worker;
    //   start_times_[i] = next_free_time[next_worker];
    //   next_free_time[next_worker] += duration;
    // }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
