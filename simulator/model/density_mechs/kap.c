/* Created by Language version: 7.7.0 */
/* VECTORIZED */
#define NRN_VECTORIZED 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib_ansi.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__kap
#define _nrn_initial _nrn_initial__kap
#define nrn_cur _nrn_cur__kap
#define _nrn_current _nrn_current__kap
#define nrn_jacob _nrn_jacob__kap
#define nrn_state _nrn_state__kap
#define _net_receive _net_receive__kap 
#define rates rates__kap 
#define states states__kap 
 
#define _threadargscomma_ _p, _ppvar, _thread, _nt,
#define _threadargsprotocomma_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt,
#define _threadargs_ _p, _ppvar, _thread, _nt
#define _threadargsproto_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 /* Thread safe. No static _p or _ppvar. */
 
#define t _nt->_t
#define dt _nt->_dt
#define gkabar _p[0]
#define vhalfn _p[1]
#define vhalfl _p[2]
#define ik _p[3]
#define ninf _p[4]
#define linf _p[5]
#define taul _p[6]
#define taun _p[7]
#define gka _p[8]
#define n _p[9]
#define l _p[10]
#define ek _p[11]
#define Dn _p[12]
#define Dl _p[13]
#define qt _p[14]
#define v _p[15]
#define _g _p[16]
#define _ion_ek	*_ppvar[0]._pval
#define _ion_ik	*_ppvar[1]._pval
#define _ion_dikdv	*_ppvar[2]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 static Datum* _extcall_thread;
 static Prop* _extcall_prop;
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
 static void _hoc_alpl(void);
 static void _hoc_alpn(void);
 static void _hoc_betl(void);
 static void _hoc_betn(void);
 static void _hoc_rates(void);
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 
#define NMODL_TEXT 1
#if NMODL_TEXT
static const char* nmodl_file_text;
static const char* nmodl_filename;
extern void hoc_reg_nmodl_text(int, const char*);
extern void hoc_reg_nmodl_filename(int, const char*);
#endif

 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _extcall_prop = _prop;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_kap", _hoc_setdata,
 "alpl_kap", _hoc_alpl,
 "alpn_kap", _hoc_alpn,
 "betl_kap", _hoc_betl,
 "betn_kap", _hoc_betn,
 "rates_kap", _hoc_rates,
 0, 0
};
#define alpl alpl_kap
#define alpn alpn_kap
#define betl betl_kap
#define betn betn_kap
 extern double alpl( _threadargsprotocomma_ double );
 extern double alpn( _threadargsprotocomma_ double );
 extern double betl( _threadargsprotocomma_ double );
 extern double betn( _threadargsprotocomma_ double );
 /* declare global and static user variables */
#define a0l a0l_kap
 double a0l = 0.05;
#define a0n a0n_kap
 double a0n = 0.05;
#define gmn gmn_kap
 double gmn = 0.55;
#define lscale lscale_kap
 double lscale = 1;
#define lmin lmin_kap
 double lmin = 2;
#define nmin nmin_kap
 double nmin = 0.1;
#define nscale nscale_kap
 double nscale = 1;
#define pw pw_kap
 double pw = -1;
#define q10 q10_kap
 double q10 = 5;
#define qq qq_kap
 double qq = 5;
#define tq tq_kap
 double tq = -40;
#define temp temp_kap
 double temp = 24;
#define zetal zetal_kap
 double zetal = 3;
#define zetan zetan_kap
 double zetan = -1.5;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "temp_kap", "degC",
 "a0n_kap", "/ms",
 "zetan_kap", "1",
 "gmn_kap", "1",
 "pw_kap", "1",
 "tq_kap", "mV",
 "qq_kap", "mV",
 "nmin_kap", "ms",
 "a0l_kap", "/ms",
 "zetal_kap", "1",
 "lmin_kap", "ms",
 "gkabar_kap", "mho/cm2",
 "vhalfn_kap", "mV",
 "vhalfl_kap", "mV",
 "ik_kap", "mA/cm2",
 "taul_kap", "ms",
 "taun_kap", "ms",
 "gka_kap", "mho/cm2",
 0,0
};
 static double delta_t = 0.01;
 static double l0 = 0;
 static double n0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "temp_kap", &temp_kap,
 "a0n_kap", &a0n_kap,
 "zetan_kap", &zetan_kap,
 "gmn_kap", &gmn_kap,
 "pw_kap", &pw_kap,
 "tq_kap", &tq_kap,
 "qq_kap", &qq_kap,
 "nmin_kap", &nmin_kap,
 "nscale_kap", &nscale_kap,
 "a0l_kap", &a0l_kap,
 "zetal_kap", &zetal_kap,
 "lmin_kap", &lmin_kap,
 "lscale_kap", &lscale_kap,
 "q10_kap", &q10_kap,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void nrn_cur(_NrnThread*, _Memb_list*, int);
static void  nrn_jacob(_NrnThread*, _Memb_list*, int);
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(_NrnThread*, _Memb_list*, int);
static void _ode_matsol(_NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[3]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"kap",
 "gkabar_kap",
 "vhalfn_kap",
 "vhalfl_kap",
 0,
 "ik_kap",
 "ninf_kap",
 "linf_kap",
 "taul_kap",
 "taun_kap",
 "gka_kap",
 0,
 "n_kap",
 "l_kap",
 0,
 0};
 static Symbol* _k_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 17, _prop);
 	/*initialize range parameters*/
 	gkabar = 0;
 	vhalfn = 11;
 	vhalfl = -56;
 	_prop->param = _p;
 	_prop->param_size = 17;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_k_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* ek */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ik */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dikdv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _kap_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("k", -10000.);
 	_k_sym = hoc_lookup("k_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 17, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 kap C:/Users/Bence/Desktop/koki-ca1-simulation/density_mechs/kap.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "K-A channel from Klee Ficker and Heinemann";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int rates(_threadargsprotocomma_ double);
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[2], _dlist1[2];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   rates ( _threadargscomma_ v ) ;
   Dn = ( ninf - n ) / taun ;
   Dl = ( linf - l ) / taul ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 rates ( _threadargscomma_ v ) ;
 Dn = Dn  / (1. - dt*( ( ( ( - 1.0 ) ) ) / taun )) ;
 Dl = Dl  / (1. - dt*( ( ( ( - 1.0 ) ) ) / taul )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
   rates ( _threadargscomma_ v ) ;
    n = n + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / taun)))*(- ( ( ( ninf ) ) / taun ) / ( ( ( ( - 1.0 ) ) ) / taun ) - n) ;
    l = l + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / taul)))*(- ( ( ( linf ) ) / taul ) / ( ( ( ( - 1.0 ) ) ) / taul ) - l) ;
   }
  return 0;
}
 
double alpn ( _threadargsprotocomma_ double _lv ) {
   double _lalpn;
 double _lzeta ;
 _lzeta = zetan + pw / ( 1.0 + exp ( ( _lv - tq ) / qq ) ) ;
   _lalpn = exp ( _lzeta * ( _lv - vhalfn ) * 1.e-3 * 9.648e4 / ( 8.315 * ( 273.16 + celsius ) ) ) ;
   
return _lalpn;
 }
 
static void _hoc_alpn(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  alpn ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double betn ( _threadargsprotocomma_ double _lv ) {
   double _lbetn;
 double _lzeta ;
 _lzeta = zetan + pw / ( 1.0 + exp ( ( _lv - tq ) / qq ) ) ;
   _lbetn = exp ( _lzeta * gmn * ( _lv - vhalfn ) * 1.e-3 * 9.648e4 / ( 8.315 * ( 273.16 + celsius ) ) ) ;
   
return _lbetn;
 }
 
static void _hoc_betn(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  betn ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double alpl ( _threadargsprotocomma_ double _lv ) {
   double _lalpl;
 _lalpl = exp ( zetal * ( _lv - vhalfl ) * 1.e-3 * 9.648e4 / ( 8.315 * ( 273.16 + celsius ) ) ) ;
   
return _lalpl;
 }
 
static void _hoc_alpl(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  alpl ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double betl ( _threadargsprotocomma_ double _lv ) {
   double _lbetl;
 _lbetl = exp ( zetal * ( _lv - vhalfl ) * 1.e-3 * 9.648e4 / ( 8.315 * ( 273.16 + celsius ) ) ) ;
   
return _lbetl;
 }
 
static void _hoc_betl(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  betl ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
static int  rates ( _threadargsprotocomma_ double _lv ) {
   double _la , _lqt ;
 _lqt = pow( q10 , ( ( celsius - 24.0 ) / 10.0 ) ) ;
   _la = alpn ( _threadargscomma_ _lv ) ;
   ninf = 1.0 / ( 1.0 + _la ) ;
   taun = betn ( _threadargscomma_ _lv ) / ( _lqt * a0n * ( 1.0 + _la ) ) ;
   if ( taun < nmin ) {
     taun = nmin ;
     }
   taun = taun / nscale ;
   _la = alpl ( _threadargscomma_ _lv ) ;
   linf = 1.0 / ( 1.0 + _la ) ;
   taul = 0.26 * ( _lv + 50.0 ) ;
   if ( taul < lmin ) {
     taul = lmin ;
     }
   taul = taul / lscale ;
    return 0; }
 
static void _hoc_rates(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r = 1.;
 rates ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ return 2;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ek = _ion_ek;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 2; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _ode_matsol1 (_p, _ppvar, _thread, _nt);
 }
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ek = _ion_ek;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_k_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_k_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_k_sym, _ppvar, 2, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  l = l0;
  n = n0;
 {
   rates ( _threadargscomma_ v ) ;
   n = ninf ;
   l = linf ;
   gka = gkabar * n * l ;
   ik = gka * ( v - ek ) ;
   }
 
}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
  ek = _ion_ek;
 initmodel(_p, _ppvar, _thread, _nt);
 }
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   gka = gkabar * n * l ;
   ik = gka * ( v - ek ) ;
   }
 _current += ik;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
  ek = _ion_ek;
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _dik;
  _dik = ik;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dikdv += (_dik - ik)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ik += ik ;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}
 
}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}
 
}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v=_v;
{
  ek = _ion_ek;
 {   states(_p, _ppvar, _thread, _nt);
  } }}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(n) - _p;  _dlist1[0] = &(Dn) - _p;
 _slist1[1] = &(l) - _p;  _dlist1[1] = &(Dl) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "kap.mod";
static const char* nmodl_file_text = 
  "TITLE K-A channel from Klee Ficker and Heinemann\n"
  ": modified to account for Dax A Current ----------\n"
  ": M.Migliore Jun 1997\n"
  "\n"
  "NEURON {\n"
  "        SUFFIX kap\n"
  "        USEION k READ ek WRITE ik\n"
  "        RANGE gkabar,gka,ik\n"
  "        RANGE ninf,linf,taul,taun\n"
  "        RANGE vhalfn,vhalfl\n"
  "        GLOBAL lmin,nscale,lscale\n"
  "}\n"
  "\n"
  "UNITS {\n"
  "        (mA) = (milliamp)\n"
  "        (mV) = (millivolt)\n"
  "        (mol) = (1)\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "        dt                              (ms)\n"
  "        v                               (mV)\n"
  "        ek                              (mV)\n"
  "        celsius                         (degC)\n"
  "\n"
  "        temp    = 24                    (degC)\n"
  "\n"
  "        gkabar                          (mho/cm2)\n"
  "\n"
  "        vhalfn  = 11                    (mV)\n"
  "        a0n     = 0.05                  (/ms)\n"
  "        zetan   = -1.5                  (1)\n"
  "        gmn     = 0.55                  (1)\n"
  "        pw      = -1                    (1)\n"
  "        tq      = -40                   (mV)\n"
  "        qq      = 5                     (mV)\n"
  "        nmin    = 0.1                   (ms)\n"
  "        nscale  = 1\n"
  "\n"
  "        vhalfl  = -56                   (mV)\n"
  "        a0l     = 0.05                  (/ms)\n"
  "        zetal   = 3                     (1)\n"
  "        lmin    = 2                     (ms)\n"
  "        lscale  = 1\n"
  "\n"
  "        q10     = 5\n"
  "}\n"
  "\n"
  "STATE {\n"
  "        n\n"
  "        l\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "        ik (mA/cm2)\n"
  "        ninf\n"
  "        linf      \n"
  "        taul  (ms)\n"
  "        taun  (ms)\n"
  "        gka   (mho/cm2)\n"
  "        qt\n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "        rates(v)\n"
  "        n=ninf\n"
  "        l=linf\n"
  "        gka = gkabar*n*l\n"
  "        ik = gka*(v-ek)\n"
  "}        \n"
  "\n"
  "BREAKPOINT {\n"
  "        SOLVE states METHOD cnexp\n"
  "        gka = gkabar*n*l\n"
  "        ik = gka*(v-ek)\n"
  "}\n"
  "\n"
  "DERIVATIVE states {\n"
  "        rates(v)\n"
  "        n' = (ninf-n)/taun\n"
  "        l' = (linf-l)/taul\n"
  "}\n"
  "\n"
  "FUNCTION alpn(v(mV)) {\n"
  "LOCAL zeta\n"
  "        zeta=zetan+pw/(1+exp((v-tq)/qq))\n"
  "        alpn = exp(zeta*(v-vhalfn)*1.e-3(V/mV)*9.648e4(coulomb/mol)/(8.315(joule/mol/degC)*(273.16(degC)+celsius))) \n"
  "}\n"
  "\n"
  "FUNCTION betn(v(mV)) {\n"
  "LOCAL zeta\n"
  "        zeta=zetan+pw/(1+exp((v-tq)/qq))\n"
  "        betn = exp(zeta*gmn*(v-vhalfn)*1.e-3(V/mV)*9.648e4(coulomb/mol)/(8.315(joule/mol/degC)*(273.16(degC)+celsius))) \n"
  "}\n"
  "\n"
  "\n"
  "FUNCTION alpl(v(mV)) {\n"
  "        alpl = exp(zetal*(v-vhalfl)*1.e-3(V/mV)*9.648e4(coulomb/mol)/(8.315(joule/mol/degC)*(273.16(degC)+celsius))) \n"
  "}\n"
  "\n"
  "FUNCTION betl(v(mV)) {\n"
  "        betl = exp(zetal*(v-vhalfl)*1.e-3(V/mV)*9.648e4(coulomb/mol)/(8.315(joule/mol/degC)*(273.16(degC)+celsius))) \n"
  "}\n"
  "\n"
  "\n"
  "PROCEDURE rates(v (mV)) { :callable from hoc\n"
  "        LOCAL a,qt\n"
  "        qt=q10^((celsius-24)/10(degC))\n"
  "        a = alpn(v)\n"
  "        ninf = 1/(1 + a)\n"
  "        taun = betn(v)/(qt*a0n*(1+a))\n"
  "        if (taun<nmin) {taun=nmin}\n"
  "        taun=taun/nscale\n"
  "\n"
  "        a = alpl(v)\n"
  "        linf = 1/(1 + a)\n"
  "        taul = 0.26(ms/mV)*(v+50)\n"
  "        if (taul<lmin) {taul=lmin}\n"
  "        taul=taul/lscale\n"
  "}\n"
  ;
#endif
