#include <vector>
#include <cstdio>
using namespace std;

struct Neuron
{
  vector<Neuron*> in, out;

  Neuron()  {}

  template<typename T> void connect_to(T& other);

  Neuron* begin() { return this; }
  Neuron* end()   { return this + 1; }
};

template<typename T>
void Neuron::connect_to(T& other) {
  for (Neuron& to : other)
    connect_to(to);
}

template<>
void Neuron::connect_to(Neuron& other) {
  out.push_back(&other);
  other.in.push_back(this);
}

struct NeuronLayer : vector<Neuron>
{
  NeuronLayer(int count)
  {
    while (count --> 0)
      emplace_back(Neuron{});
  }

  template <typename T> void connect_to(T& other)
  {
    for (Neuron& from : *this)
      for (Neuron& to : other)
        from.connect_to(to);
  }
};

int main()
{
  Neuron n, n2;
  NeuronLayer nl{3}, nl2{5};

  n.connect_to(n2); // Neuron::connect_to<Neuron>
  n.connect_to(nl); // Neuron::connect_to<T = NL>
  nl.connect_to(n); // what we did begin()/end() for
  nl.connect_to(nl2); // NL::connect_to<T = NL>

  getchar();
  return 0;
}