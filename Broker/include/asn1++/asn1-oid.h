#ifndef ASN1OID_H
#define ASN1OID_H

#include <OBJECT_IDENTIFIER.h>
#include <string>

using namespace std;

// Classe para auxiliar o acesso e modificação de OBJECT IDENTIFIER
class ASN1Oid {
 private:
  OBJECT_IDENTIFIER_t * ptr;
  bool external;
 public:
  // Construtor: o parâmetro é um OBJECT IDENTIFIER
  ASN1Oid(OBJECT_IDENTIFIER_t & oid);

  // Construtor: cria automaticamente o OID encapsulado
  ASN1Oid();

  virtual ~ASN1Oid();

  // Operador de atribuição: facilita a definição do OID por meio de uma string (ex: "1.3.6.4")
  virtual ASN1Oid & operator=(const string & oid);

  // retorna o valor do OID como uma string
  string str() const;

  // Operador de concatenação, que posibilita concatenar OIDs
  virtual ASN1Oid & operator+=(const ASN1Oid & other);
  virtual ASN1Oid & operator+=(const string & oid);

  // Iterador: possibilita o acesso sequencial a cada número do OID
  class iterator {
    friend class ASN1Oid;
    private:
     int pos;
     long *arcs;
     int len;
    public:
      iterator(const ASN1Oid & ptr);
      iterator();
      iterator(const iterator & it);
      ~iterator();
      iterator& operator++();
      iterator operator++(int);
      long& operator*() const;
      bool operator==(const iterator &it) const;
      bool operator!=(const iterator &it) const;
  };  
  iterator begin() const;
  iterator end() const;
 protected:
  virtual int get_arcs(OBJECT_IDENTIFIER_t *oid,
        void *arcs, unsigned int type_size, unsigned int slots) const;
  virtual int set_arcs(OBJECT_IDENTIFIER_t *oid,
        void *arcs, unsigned int type_size, unsigned int slots);
  void fromString(const string & oid);
};

#endif
