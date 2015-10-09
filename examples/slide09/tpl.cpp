template<class Iter, class Fct>Fct my_for_each(Iter b, Iter e, Fct f)
{
  while(b!=e) f(*b++);
  return f;
}
