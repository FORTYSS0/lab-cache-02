// Copyright 2020 by FORTYSS

#include <cacher.hpp>
std::vector<uint> Genarr(){
  double min = 0.125, max = 8;
  int flag=0, sh=0;
  std::vector<double> cache;
  cache.push_back(min);
  while (flag < max){
    flag = pow(2,sh);
    cache.push_back(flag);
    sh++;
  }
  cache.push_back(max*1.5);
  std::vector<uint> buf(cache.size());
  for (double i = 0; i < cache.size(); ++i) {
    buf[i] = cache[i] * (pow(2, 18));
  }
  return  buf;
}
auto progrev(uint64_t size){
  auto arr= new long double [size];

  for (size_t i = 0; i < size; i+=sets) {
    arr[i] = random();
  }
  return arr;
}
std::vector<double> pryam(const std::vector<uint>& buf) {
  std::vector<double> out;
  for (size_t k = 0; k < static_cast<size_t>(buf.size()); k++) {
    auto arr = progrev(buf[k]);
    long double sum = 0;
    for (size_t i = 0; i < buf[k]; i += sets) {
      sum += arr[i];
    }
    sum = 0;
    double rez =0;
    //auto time1 = std::chrono::high_resolution_clock::now();
    for (size_t j = 0; j < expcol; j++) {
      auto time1 = std::chrono::high_resolution_clock::now();
      for (size_t i = 0; i < buf[k]; i += sets) {
        sum += arr[i];
      }
      auto time2 = std::chrono::high_resolution_clock::now();
      rez += static_cast<double>(
          (std::chrono::nanoseconds(time2 - time1).count()));
    }
    delete[] arr;
    //auto time2 = std::chrono::high_resolution_clock::now();
    out.push_back((rez/expcol));
  }
  return out;
}
std::vector<double> back(const std::vector<uint>& buf) {
  std::vector<double> out;
  for (size_t k = 0; k < static_cast<size_t>(buf.size()); k++) {
    auto arr = progrev(buf[k]);
    long double sum = 0;
    for (size_t i = 0; i < buf[k]; i += sets) {
      sum += arr[i];
    }
    sum = 0;
    double rez = 0;
    // auto time1 = std::chrono::high_resolution_clock::now();
    for (size_t j = 0; j < expcol; j++) {
      auto time1 = std::chrono::high_resolution_clock::now();
      for (int i = buf[k] - 1; i > -1; i -= sets) {
        sum += arr[i];
      }
      auto time2 = std::chrono::high_resolution_clock::now();
      rez += static_cast<double>(
          (std::chrono::nanoseconds(time2 - time1).count()));
    }
    delete[] arr;
    // auto time2 = std::chrono::high_resolution_clock::now();
    out.push_back((rez / expcol));
  }
  return out;
}
std::vector<double> rand(const std::vector<uint>& buf) {
  std::vector<double> out;
  for (size_t k = 0; k < static_cast<size_t>(buf.size()); k++) {
  auto arr = progrev(buf[k]);
  long double sum = 0;
  std::vector<size_t> x(buf[k]);
  for (size_t i = 0; i < buf[k]; i++) {
    sum += arr[i];
    if(i%sets == 0) {
      x[i] = i;
    }
  }
  sum = 0;
  double rez = 0;
  srand(unsigned(time(0)));
  random_shuffle(x.begin(), x.end());
    for(size_t i = 0; i < expcol; i++) {
    auto time1 = std::chrono::high_resolution_clock::now();
    for (size_t j = 0; j < buf[k]; j += sets) {
      sum += arr[x[i]];
    }
    auto time2 = std::chrono::high_resolution_clock::now();
    rez +=
        static_cast<double>((std::chrono::nanoseconds(time2 - time1).count()));
  }
    delete[] arr;
  //auto time2 = std::chrono::high_resolution_clock::now();
    out.push_back(rez / expcol);
  }

  return out;
}
void Out(const std::vector<uint>& buf) {
 cout << R"(investigation:
    travel_variant: Pramoy
    experiments:
    number: 1
    input_data:
    buffer_size:)";
 for(size_t i =0; i<buf.size(); i++){
   std::cout<< " " << (buf[i]/(pow(2, 18)))<<"Mb,";
 }
    cout<< std::endl << R"(results:
    duration:)";
 std::vector<double> vect = pryam(buf);
 for(size_t i =0; i<vect.size(); i++){
   cout << " " << vect[i] << " nanosec.";
 }
cout << std::endl << R"(investigation:
    travel_variant: Obratn
    experiments:
    number: 1
    input_data:
    buffer_size:)";
  for(size_t i =0; i<buf.size(); i++){
    std::cout<< " " << (buf[i]/(pow(2, 18)))<<"Mb,";
  }
  cout<< std::endl << R"(results:
    duration:)";
  vect = back(buf);
  for(size_t i =0; i<vect.size(); i++){
    cout << " " << vect[i] << " nanosec.";
  }
  cout << std::endl << R"(investigation:
    travel_variant: Random
    experiments:
    number: 1
    input_data:
    buffer_size:)";
  for(size_t i =0; i<buf.size(); i++){
    std::cout<< " " << (buf[i]/(pow(2, 18)))<<"Mb,";
  }
  cout<< std::endl << R"(results:
    duration:)";
  vect = rand(buf);
  for(size_t i =0; i<vect.size(); i++){
    cout << " " << vect[i] << " nanosec.";
  }
}