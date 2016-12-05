#ifndef ASN1_PARSER_ATIVO_H
#define ASN1_PARSER_ATIVO_H

#include <asn1++/asn1++.h>

#include<Publish.h>
#include<Subscribe.h>
#include<Unsubscribe.h>
#include<ACKsubs.h>
#include<Notify.h>
#include<Ativo.h>

class TPublish : public ASN1DataType<Publish_t> {
 public:
 private:
  ASN1Oid * m_subject;
 public:
  TPublish() : ASN1DataType<Publish_t>(&asn_DEF_Publish) {
    init();
  }
  TPublish(Publish_t * ptr) : ASN1DataType<Publish_t>(&asn_DEF_Publish, ptr) {
    destroy = false;
    init();
  }
  TPublish(const TPublish & o) : ASN1DataType<Publish_t>(&asn_DEF_Publish, o.pkt) {
    init();
    destroy = false;
  }
  void init() {
    m_subject = new ASN1Oid(pkt->subject);
  }
  virtual ~TPublish() {
    delete m_subject;
  }
  TPublish & operator=(const TPublish & o) {
    if (destroy) delete pkt;
    pkt = o.pkt;
    DESC = o.DESC;
    delete m_subject;
    init();
    destroy = false;
    return *this;
}
  bool get_value() { return pkt->value;}
  void set_value(bool arg) { pkt->value = arg;}
  ASN1Oid & get_subject_attr() { return *m_subject;}
  string get_subject() { return m_subject->str();}
  void set_subject(const string & arg) { *m_subject = arg;}
  class DerSerializer : public DERSerializer<Publish_t> {
  public:
    DerSerializer(ostream & out) : DERSerializer<Publish_t>(&asn_DEF_Publish, out) {}
    ~DerSerializer() {}
    ssize_t serialize(TPublish & pkt) {DERSerializer<Publish_t>::serialize(pkt);}
  };
  class DerDeserializer : public DERDeserializer<Publish_t> {
  public:
    DerDeserializer(istream & inp) : DERDeserializer<Publish_t>(&asn_DEF_Publish, inp) {}
    ~DerDeserializer() {}
    TPublish * deserialize() {
      ASN1DataType<Publish> * p = DERDeserializer<Publish_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TPublish * scan() {
      ASN1DataType<Publish> * p = DERDeserializer<Publish_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TPublish * get_obj(ASN1DataType<Publish_t> * p) {
      TPublish * obj = new TPublish(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
  class XerSerializer : public XERSerializer<Publish_t> {
  public:
    XerSerializer(ostream & out) : XERSerializer<Publish_t>(&asn_DEF_Publish, out) {}
    ~XerSerializer() {}
    ssize_t serialize(TPublish & pkt) {XERSerializer<Publish_t>::serialize(pkt);}
  };
  class XerDeserializer : public XERDeserializer<Publish_t> {
  public:
    XerDeserializer(istream & inp) : XERDeserializer<Publish_t>(&asn_DEF_Publish, inp) {}
    ~XerDeserializer() {}
    TPublish * deserialize() {
      ASN1DataType<Publish> * p = XERDeserializer<Publish_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TPublish * scan() {
      ASN1DataType<Publish> * p = XERDeserializer<Publish_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TPublish * get_obj(ASN1DataType<Publish_t> * p) {
      TPublish * obj = new TPublish(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
};

class TSubscribe : public ASN1DataType<Subscribe_t> {
 public:
 private:
  ASN1Oid * m_subject;
 public:
  TSubscribe() : ASN1DataType<Subscribe_t>(&asn_DEF_Subscribe) {
    init();
  }
  TSubscribe(Subscribe_t * ptr) : ASN1DataType<Subscribe_t>(&asn_DEF_Subscribe, ptr) {
    destroy = false;
    init();
  }
  TSubscribe(const TSubscribe & o) : ASN1DataType<Subscribe_t>(&asn_DEF_Subscribe, o.pkt) {
    init();
    destroy = false;
  }
  void init() {
    m_subject = new ASN1Oid(pkt->subject);
  }
  virtual ~TSubscribe() {
    delete m_subject;
  }
  TSubscribe & operator=(const TSubscribe & o) {
    if (destroy) delete pkt;
    pkt = o.pkt;
    DESC = o.DESC;
    delete m_subject;
    init();
    destroy = false;
    return *this;
}
  ASN1Oid & get_subject_attr() { return *m_subject;}
  string get_subject() { return m_subject->str();}
  void set_subject(const string & arg) { *m_subject = arg;}
  class DerSerializer : public DERSerializer<Subscribe_t> {
  public:
    DerSerializer(ostream & out) : DERSerializer<Subscribe_t>(&asn_DEF_Subscribe, out) {}
    ~DerSerializer() {}
    ssize_t serialize(TSubscribe & pkt) {DERSerializer<Subscribe_t>::serialize(pkt);}
  };
  class DerDeserializer : public DERDeserializer<Subscribe_t> {
  public:
    DerDeserializer(istream & inp) : DERDeserializer<Subscribe_t>(&asn_DEF_Subscribe, inp) {}
    ~DerDeserializer() {}
    TSubscribe * deserialize() {
      ASN1DataType<Subscribe> * p = DERDeserializer<Subscribe_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TSubscribe * scan() {
      ASN1DataType<Subscribe> * p = DERDeserializer<Subscribe_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TSubscribe * get_obj(ASN1DataType<Subscribe_t> * p) {
      TSubscribe * obj = new TSubscribe(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
  class XerSerializer : public XERSerializer<Subscribe_t> {
  public:
    XerSerializer(ostream & out) : XERSerializer<Subscribe_t>(&asn_DEF_Subscribe, out) {}
    ~XerSerializer() {}
    ssize_t serialize(TSubscribe & pkt) {XERSerializer<Subscribe_t>::serialize(pkt);}
  };
  class XerDeserializer : public XERDeserializer<Subscribe_t> {
  public:
    XerDeserializer(istream & inp) : XERDeserializer<Subscribe_t>(&asn_DEF_Subscribe, inp) {}
    ~XerDeserializer() {}
    TSubscribe * deserialize() {
      ASN1DataType<Subscribe> * p = XERDeserializer<Subscribe_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TSubscribe * scan() {
      ASN1DataType<Subscribe> * p = XERDeserializer<Subscribe_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TSubscribe * get_obj(ASN1DataType<Subscribe_t> * p) {
      TSubscribe * obj = new TSubscribe(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
};

class TUnsubscribe : public ASN1DataType<Unsubscribe_t> {
 public:
 private:
  ASN1Oid * m_subject;
 public:
  TUnsubscribe() : ASN1DataType<Unsubscribe_t>(&asn_DEF_Unsubscribe) {
    init();
  }
  TUnsubscribe(Unsubscribe_t * ptr) : ASN1DataType<Unsubscribe_t>(&asn_DEF_Unsubscribe, ptr) {
    destroy = false;
    init();
  }
  TUnsubscribe(const TUnsubscribe & o) : ASN1DataType<Unsubscribe_t>(&asn_DEF_Unsubscribe, o.pkt) {
    init();
    destroy = false;
  }
  void init() {
    m_subject = new ASN1Oid(pkt->subject);
  }
  virtual ~TUnsubscribe() {
    delete m_subject;
  }
  TUnsubscribe & operator=(const TUnsubscribe & o) {
    if (destroy) delete pkt;
    pkt = o.pkt;
    DESC = o.DESC;
    delete m_subject;
    init();
    destroy = false;
    return *this;
}
  ASN1Oid & get_subject_attr() { return *m_subject;}
  string get_subject() { return m_subject->str();}
  void set_subject(const string & arg) { *m_subject = arg;}
  class DerSerializer : public DERSerializer<Unsubscribe_t> {
  public:
    DerSerializer(ostream & out) : DERSerializer<Unsubscribe_t>(&asn_DEF_Unsubscribe, out) {}
    ~DerSerializer() {}
    ssize_t serialize(TUnsubscribe & pkt) {DERSerializer<Unsubscribe_t>::serialize(pkt);}
  };
  class DerDeserializer : public DERDeserializer<Unsubscribe_t> {
  public:
    DerDeserializer(istream & inp) : DERDeserializer<Unsubscribe_t>(&asn_DEF_Unsubscribe, inp) {}
    ~DerDeserializer() {}
    TUnsubscribe * deserialize() {
      ASN1DataType<Unsubscribe> * p = DERDeserializer<Unsubscribe_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TUnsubscribe * scan() {
      ASN1DataType<Unsubscribe> * p = DERDeserializer<Unsubscribe_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TUnsubscribe * get_obj(ASN1DataType<Unsubscribe_t> * p) {
      TUnsubscribe * obj = new TUnsubscribe(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
  class XerSerializer : public XERSerializer<Unsubscribe_t> {
  public:
    XerSerializer(ostream & out) : XERSerializer<Unsubscribe_t>(&asn_DEF_Unsubscribe, out) {}
    ~XerSerializer() {}
    ssize_t serialize(TUnsubscribe & pkt) {XERSerializer<Unsubscribe_t>::serialize(pkt);}
  };
  class XerDeserializer : public XERDeserializer<Unsubscribe_t> {
  public:
    XerDeserializer(istream & inp) : XERDeserializer<Unsubscribe_t>(&asn_DEF_Unsubscribe, inp) {}
    ~XerDeserializer() {}
    TUnsubscribe * deserialize() {
      ASN1DataType<Unsubscribe> * p = XERDeserializer<Unsubscribe_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TUnsubscribe * scan() {
      ASN1DataType<Unsubscribe> * p = XERDeserializer<Unsubscribe_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TUnsubscribe * get_obj(ASN1DataType<Unsubscribe_t> * p) {
      TUnsubscribe * obj = new TUnsubscribe(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
};

class TACKsubs : public ASN1DataType<ACKsubs_t> {
 public:
 private:
  ASN1Oid * m_subject;
 public:
  TACKsubs() : ASN1DataType<ACKsubs_t>(&asn_DEF_ACKsubs) {
    init();
  }
  TACKsubs(ACKsubs_t * ptr) : ASN1DataType<ACKsubs_t>(&asn_DEF_ACKsubs, ptr) {
    destroy = false;
    init();
  }
  TACKsubs(const TACKsubs & o) : ASN1DataType<ACKsubs_t>(&asn_DEF_ACKsubs, o.pkt) {
    init();
    destroy = false;
  }
  void init() {
    m_subject = new ASN1Oid(pkt->subject);
  }
  virtual ~TACKsubs() {
    delete m_subject;
  }
  TACKsubs & operator=(const TACKsubs & o) {
    if (destroy) delete pkt;
    pkt = o.pkt;
    DESC = o.DESC;
    delete m_subject;
    init();
    destroy = false;
    return *this;
}
  bool get_value() { return pkt->value;}
  void set_value(bool arg) { pkt->value = arg;}
  ASN1Oid & get_subject_attr() { return *m_subject;}
  string get_subject() { return m_subject->str();}
  void set_subject(const string & arg) { *m_subject = arg;}
  class DerSerializer : public DERSerializer<ACKsubs_t> {
  public:
    DerSerializer(ostream & out) : DERSerializer<ACKsubs_t>(&asn_DEF_ACKsubs, out) {}
    ~DerSerializer() {}
    ssize_t serialize(TACKsubs & pkt) {DERSerializer<ACKsubs_t>::serialize(pkt);}
  };
  class DerDeserializer : public DERDeserializer<ACKsubs_t> {
  public:
    DerDeserializer(istream & inp) : DERDeserializer<ACKsubs_t>(&asn_DEF_ACKsubs, inp) {}
    ~DerDeserializer() {}
    TACKsubs * deserialize() {
      ASN1DataType<ACKsubs> * p = DERDeserializer<ACKsubs_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TACKsubs * scan() {
      ASN1DataType<ACKsubs> * p = DERDeserializer<ACKsubs_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TACKsubs * get_obj(ASN1DataType<ACKsubs_t> * p) {
      TACKsubs * obj = new TACKsubs(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
  class XerSerializer : public XERSerializer<ACKsubs_t> {
  public:
    XerSerializer(ostream & out) : XERSerializer<ACKsubs_t>(&asn_DEF_ACKsubs, out) {}
    ~XerSerializer() {}
    ssize_t serialize(TACKsubs & pkt) {XERSerializer<ACKsubs_t>::serialize(pkt);}
  };
  class XerDeserializer : public XERDeserializer<ACKsubs_t> {
  public:
    XerDeserializer(istream & inp) : XERDeserializer<ACKsubs_t>(&asn_DEF_ACKsubs, inp) {}
    ~XerDeserializer() {}
    TACKsubs * deserialize() {
      ASN1DataType<ACKsubs> * p = XERDeserializer<ACKsubs_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TACKsubs * scan() {
      ASN1DataType<ACKsubs> * p = XERDeserializer<ACKsubs_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TACKsubs * get_obj(ASN1DataType<ACKsubs_t> * p) {
      TACKsubs * obj = new TACKsubs(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
};

class TNotify : public ASN1DataType<Notify_t> {
 public:
 private:
  ASN1Oid * m_subject;
 public:
  TNotify() : ASN1DataType<Notify_t>(&asn_DEF_Notify) {
    init();
  }
  TNotify(Notify_t * ptr) : ASN1DataType<Notify_t>(&asn_DEF_Notify, ptr) {
    destroy = false;
    init();
  }
  TNotify(const TNotify & o) : ASN1DataType<Notify_t>(&asn_DEF_Notify, o.pkt) {
    init();
    destroy = false;
  }
  void init() {
    m_subject = new ASN1Oid(pkt->subject);
  }
  virtual ~TNotify() {
    delete m_subject;
  }
  TNotify & operator=(const TNotify & o) {
    if (destroy) delete pkt;
    pkt = o.pkt;
    DESC = o.DESC;
    delete m_subject;
    init();
    destroy = false;
    return *this;
}
  bool get_value() { return pkt->value;}
  void set_value(bool arg) { pkt->value = arg;}
  ASN1Oid & get_subject_attr() { return *m_subject;}
  string get_subject() { return m_subject->str();}
  void set_subject(const string & arg) { *m_subject = arg;}
  class DerSerializer : public DERSerializer<Notify_t> {
  public:
    DerSerializer(ostream & out) : DERSerializer<Notify_t>(&asn_DEF_Notify, out) {}
    ~DerSerializer() {}
    ssize_t serialize(TNotify & pkt) {DERSerializer<Notify_t>::serialize(pkt);}
  };
  class DerDeserializer : public DERDeserializer<Notify_t> {
  public:
    DerDeserializer(istream & inp) : DERDeserializer<Notify_t>(&asn_DEF_Notify, inp) {}
    ~DerDeserializer() {}
    TNotify * deserialize() {
      ASN1DataType<Notify> * p = DERDeserializer<Notify_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TNotify * scan() {
      ASN1DataType<Notify> * p = DERDeserializer<Notify_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TNotify * get_obj(ASN1DataType<Notify_t> * p) {
      TNotify * obj = new TNotify(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
  class XerSerializer : public XERSerializer<Notify_t> {
  public:
    XerSerializer(ostream & out) : XERSerializer<Notify_t>(&asn_DEF_Notify, out) {}
    ~XerSerializer() {}
    ssize_t serialize(TNotify & pkt) {XERSerializer<Notify_t>::serialize(pkt);}
  };
  class XerDeserializer : public XERDeserializer<Notify_t> {
  public:
    XerDeserializer(istream & inp) : XERDeserializer<Notify_t>(&asn_DEF_Notify, inp) {}
    ~XerDeserializer() {}
    TNotify * deserialize() {
      ASN1DataType<Notify> * p = XERDeserializer<Notify_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TNotify * scan() {
      ASN1DataType<Notify> * p = XERDeserializer<Notify_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TNotify * get_obj(ASN1DataType<Notify_t> * p) {
      TNotify * obj = new TNotify(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
};

class TAtivo : public ASN1DataType<Ativo_t> {
 public:
  class Choice_id {
   private:
    typename Ativo_t::id * ptr;
    void check(id_PR attr) {
      if (ptr->present == id_PR_NOTHING) ptr->present = attr;
      if (ptr->present != attr) throw -1;
    }
   public:
    Choice_id(typename Ativo_t::id & rec) : ptr(&rec) {
    }
    Choice_id(typename Ativo_t::id & rec, bool reset) : ptr(&rec) {
      if (reset) ptr->present = id_PR_NOTHING;
    }
    ~Choice_id() {}
    id_PR get_choice() { return ptr->present;}
    void set_sub() { ptr->present = id_PR_sub; }
    void set_sub(const TSubscribe & arg) {
      ptr->present = id_PR_sub;
    }
    TSubscribe get_sub() {
      check(id_PR_sub);
      TSubscribe pld(&ptr->choice.sub);
      pld.set_destroy(false);
      return pld;
    }
    void set_noty() { ptr->present = id_PR_noty; }
    void set_noty(const TNotify & arg) {
      ptr->present = id_PR_noty;
    }
    TNotify get_noty() {
      check(id_PR_noty);
      TNotify pld(&ptr->choice.noty);
      pld.set_destroy(false);
      return pld;
    }
    void set_pub() { ptr->present = id_PR_pub; }
    void set_pub(const TPublish & arg) {
      ptr->present = id_PR_pub;
    }
    TPublish get_pub() {
      check(id_PR_pub);
      TPublish pld(&ptr->choice.pub);
      pld.set_destroy(false);
      return pld;
    }
    void set_un() { ptr->present = id_PR_un; }
    void set_un(const TUnsubscribe & arg) {
      ptr->present = id_PR_un;
    }
    TUnsubscribe get_un() {
      check(id_PR_un);
      TUnsubscribe pld(&ptr->choice.un);
      pld.set_destroy(false);
      return pld;
    }
  };

 private:
  Choice_id * m_id;
 public:
  TAtivo() : ASN1DataType<Ativo_t>(&asn_DEF_Ativo) {
    init();
  }
  TAtivo(Ativo_t * ptr) : ASN1DataType<Ativo_t>(&asn_DEF_Ativo, ptr) {
    destroy = false;
    init();
  }
  TAtivo(const TAtivo & o) : ASN1DataType<Ativo_t>(&asn_DEF_Ativo, o.pkt) {
    init();
    destroy = false;
  }
  void init() {
    m_id = new Choice_id(pkt->id, destroy);
  }
  virtual ~TAtivo() {
    delete m_id;
  }
  TAtivo & operator=(const TAtivo & o) {
    if (destroy) delete pkt;
    pkt = o.pkt;
    DESC = o.DESC;
    delete m_id;
    init();
    destroy = false;
    return *this;
}
  Choice_id & get_id() { return *m_id;}
  class DerSerializer : public DERSerializer<Ativo_t> {
  public:
    DerSerializer(ostream & out) : DERSerializer<Ativo_t>(&asn_DEF_Ativo, out) {}
    ~DerSerializer() {}
    ssize_t serialize(TAtivo & pkt) {DERSerializer<Ativo_t>::serialize(pkt);}
  };
  class DerDeserializer : public DERDeserializer<Ativo_t> {
  public:
    DerDeserializer(istream & inp) : DERDeserializer<Ativo_t>(&asn_DEF_Ativo, inp) {}
    ~DerDeserializer() {}
    TAtivo * deserialize() {
      ASN1DataType<Ativo> * p = DERDeserializer<Ativo_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TAtivo * scan() {
      ASN1DataType<Ativo> * p = DERDeserializer<Ativo_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TAtivo * get_obj(ASN1DataType<Ativo_t> * p) {
      TAtivo * obj = new TAtivo(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
  class XerSerializer : public XERSerializer<Ativo_t> {
  public:
    XerSerializer(ostream & out) : XERSerializer<Ativo_t>(&asn_DEF_Ativo, out) {}
    ~XerSerializer() {}
    ssize_t serialize(TAtivo & pkt) {XERSerializer<Ativo_t>::serialize(pkt);}
  };
  class XerDeserializer : public XERDeserializer<Ativo_t> {
  public:
    XerDeserializer(istream & inp) : XERDeserializer<Ativo_t>(&asn_DEF_Ativo, inp) {}
    ~XerDeserializer() {}
    TAtivo * deserialize() {
      ASN1DataType<Ativo> * p = XERDeserializer<Ativo_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TAtivo * scan() {
      ASN1DataType<Ativo> * p = XERDeserializer<Ativo_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TAtivo * get_obj(ASN1DataType<Ativo_t> * p) {
      TAtivo * obj = new TAtivo(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
};

#endif
