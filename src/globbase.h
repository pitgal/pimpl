#include <memory>

struct Foo;
struct Bar;

class GlobBase {
private:
  class Impl;
  std::unique_ptr<Impl> pImpl;

public:
  GlobBase();
  ~GlobBase();
  GlobBase(const GlobBase& rhs) = delete;
  GlobBase& operator=(const GlobBase& rhs) = delete;
  GlobBase(GlobBase&& rhs);
  GlobBase& operator=(GlobBase&& rhs);
  Bar* getBar() const;
  Foo* getFoo() const;
};