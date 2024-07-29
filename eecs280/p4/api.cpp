// Project UID c1f28c309e55405daf00c565d57ff9ad
#include <iostream>
#include <list>
#include <string>
#include "json.hpp"
using nlohmann::json;
using namespace std;

struct student {
  string uniq;
  string loc;
};


void error() {
  cout << "HTTP/1.1 400 Bad Request\n";
  cout << "Content-Type: application/json; charset=utf-8\n";
  cout << "Content-Length: 0\n";
  cout << endl;
}

void get1() {
  json res = {
    {"queue_head_url", "http://localhost/queue/head/"},
    {"queue_list_url", "http://localhost/queue/"},
    {"queue_tail_url", "http://localhost/queue/tail/"}
  };
  string str = res.dump(4) + "\n";
  cout << "HTTP/1.1 200 OK" << endl;
  cout << "Content-Type: application/json; charset=utf-8" << endl;
  cout << "Content-Length: 160" << endl << endl;
  cout << str;
}

void get2(list<student> &stu) {
  if (stu.empty()) {
    error();
    return;
  }
  json res = {
    {"location", stu.front().loc},
    {"position", 1},
    {"uniqname", stu.front().uniq}
  };
  string str = res.dump(4) + "\n";
  cout << "HTTP/1.1 200 OK" << endl;
  cout << "Content-Type: application/json; charset=utf-8" << endl;
  cout << "Content-Length: " << str.length() << endl << endl;
  cout << str;
}

void get3(list<student> &stu) {
  cout << "HTTP/1.1 200 OK" << endl;
  cout << "Content-Type: application/json; charset=utf-8" << endl;
  if (stu.empty()) {
    json out = {
      {"count", 0},
      {"results", nullptr}
    };
    string str = out.dump(4) + "\n";
    cout << "Content-Length: " << str.length() << endl << endl;
    cout << str;
    return;
  }
  json jarr;
  int counter = 0;
  for (auto it = stu.begin(); it != stu.end(); ++it) {
    counter++;
    json res = {
      {"location", (*it).loc},
      {"position", counter},
      {"uniqname", (*it).uniq}
    };
    jarr.push_back(res);
  }
  json out = {
    {"count", counter},
    {"results", jarr}
  };
  string str = out.dump(4) + "\n";
  cout << "Content-Length: " << str.length() << endl << endl;
  cout << str;
}

void GET(list<student> &stu) {
  string path;
  string lese;
  json target;
  int jlength = 0;
  cin >> path >> lese >> lese >> lese >> lese >> lese >> lese >> lese >> jlength;
  if (jlength != 0) {
    cin >> target;
  }
  if (path == "/api/") {
    get1();
  }
  else if (path == "/api/queue/head/") {
    get2(stu);
  }
  else if (path == "/api/queue/") {
    get3(stu);
  }
  else {
    error();
    return;
  }
}

void POST(list<student> &stu) {
  string path;
  string lese;
  json target;
  int jlength = 0;
  cin >> path >> lese >> lese >> lese >> lese >> lese >> lese >> lese >> jlength;
  if (jlength != 0) {
    cin >> target;
  }
  if (path != "/api/queue/tail/"){
    error();
    return;
  }
  cout << "HTTP/1.1 201 Created" << endl;
  cout << "Content-Type: application/json; charset=utf-8" << endl;
  stu.push_back({target["uniqname"], target["location"]});
  json obj = {
    {"location", stu.back().loc},
    {"position", stu.size()},
    {"uniqname", stu.back().uniq}
  };
  string str = obj.dump(4) + "\n";
  cout << "Content-Length: " << str.length() << endl << endl;
  cout << str;
}

void DELETE(list<student> &stu) {
  string path;
  string lese;
  json target;
  int jlength = 0;
  cin >> path >> lese >> lese >> lese >> lese >> lese >> lese >> lese >> jlength;
  if (jlength != 0) {
    cin >> target;
  }
  if (path != "/api/queue/head/"){
    error();
    return;
  }
  cout << "HTTP/1.1 204 No Content" << endl;
  cout << "Content-Type: application/json; charset=utf-8" << endl;
  stu.pop_front();
  cout << "Content-Length: 0" << endl << endl;
}

int main() {
  list<student> stu;
  string method;
  while (cin >> method) {
    if (method == "GET") {
      GET(stu);
    }
    else if (method == "POST") {
      POST(stu);
    }
    else if (method == "DELETE") {
      DELETE(stu);
    }
  }
  return 0;
}

