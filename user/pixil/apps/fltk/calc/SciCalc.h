/*                                                                       
 * Copyright (c) 2003 Century Software, Inc.   All Rights Reserved.     
 *                                                                       
 * This file is part of the PIXIL Operating Environment                 
 *                                                                       
 * The use, copying and distribution of this file is governed by one    
 * of two licenses, the PIXIL Commercial License, or the GNU General    
 * Public License, version 2.                                           
 *                                                                       
 * Licensees holding a valid PIXIL Commercial License may use this file 
 * in accordance with the PIXIL Commercial License Agreement provided   
 * with the Software. Others are governed under the terms of the GNU   
 * General Public License version 2.                                    
 *                                                                       
 * This file may be distributed and/or modified under the terms of the  
 * GNU General Public License version 2 as published by the Free        
 * Software Foundation and appearing in the file LICENSE.GPL included   
 * in the packaging of this file.                                      
 *                                                                       
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING  
 * THE WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A            
 * PARTICULAR PURPOSE.                                                  
 *                                                                       
 * RESTRICTED RIGHTS LEGEND                                             
 *                                                                     
 * Use, duplication, or disclosure by the government is subject to      
 * restriction as set forth in paragraph (b)(3)(b) of the Rights in     
 * Technical Data and Computer Software clause in DAR 7-104.9(a).       
 *                                                                      
 * See http://embedded.centurysoftware.com/gpl/ for GPL licensing       
 * information.                                                         
 *                                                                      
 * See http://embedded.centurysoftware.com/license.html or              
 * email cetsales@centurysoftware.com for information about the PIXIL   
 * Commercial License Agreement, or if any conditions of this licensing 
 * are not clear to you.                                                
 */


// generated by Fast Light User Interface Designer (fluid) version 2.00

#ifndef SciCalc_h
#define SciCalc_h
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_Scroll.H>

#include <FL/Flv_Table_Child.H>
#include <FL/Fl_Editor.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Editor.H>



//#include <FL/Fl_Group.H>
//#include <FL/n_x.h>

#include <nxapp.h>
#include <nxwindow.h>
#include <nxdb.h>
#include <catlist.h>

#include "StaticText.h"

#define FL_BUTT_GEO(COL,ROW)	GetButtonPosX(COL),GetButtonPosY(ROW),GetButtonWidth(),GetButtonHeight()


class SciCalc:public Fl_Double_Window, public NxApp
{


    NxApp *thisnxapp;
    Fl_Double_Window *main_window;

    Fl_Double_Window *status_window;
    Fl_Double_Window *sci_view_window;
    Fl_Double_Window *simple_view_window;

    Fl_Double_Window *num_mode_window;
    Fl_Group *out_data_group;
    Fl_Button *to_sci_mode;
    Fl_Button *to_simple_mode;

    bool SciMode;
    int old_w;
    int old_h;
    int tmp_x;
    int tmp_y;
    int tmp_w;
    int tmp_h;

    bool ButtonGeometryValid;
    int button_h;
    int button_w;
    int button_win_x;
    int button_win_y;
    int button_win_w;
    int button_win_h;
    int button_win_row;
    int button_win_col;

    enum
    { MaxNumBrkts = 10 };
    enum Operator
    { PLUS, MINUS, MULT, DIV, POW, INVPOW, EVAL };
    enum mode
    { NONE = 0, DOT = -1, NORM = -2, EXP = -3 };
    double value[4 * (MaxNumBrkts + 1)]; /* The values on the stack */ ;
    int priority[6]; /* the priorities of each operator */ ;
    int oper[3 * (MaxNumBrkts + 1)]; /* the operators between them */ ;
    int top; /* the top of the stack */ ;
    int startbrkt[(MaxNumBrkts + 1)];
    /* the positions of the left brackets */ ;
    int currentbrkt; /* bracketing we are in */ ;
    double mem; /* The memory value */ ;
    int ready;			/* Whether last number is ready.
				   if "ready" is set, then typing another number
				   overwrites the current number. */ ;
    int dot; /* Whether the dot has been typed */ ;
    double diver; /* The divider when behind the dot */ ;
    int behind; /* Number of digits behind dot */ ;
    int inv; /* Whether inverse key is depressed */ ;
    int emode; /* Whether we are entering the exponent */ ;
    int exponent; /* the exponent value whilst entering exponent */ ;
    double mantissa; /* the mantissa value whilst entering exponent */ ;
    int base; /* the base we are working in (2,8,10 or 16) */ ;
    int drgmode; /* whether we are in deg, rad or grad mode */ ;
  public:
      SciCalc(bool);
//      virtual ~SciCalc();
  private:
      Fl_Double_Window * win;
    StaticText *leddisplay;
    inline void cb_leddisplay_i(StaticText *, void *);
    static void cb_leddisplay(StaticText *, void *);
    StaticText *box_DEGRAD;
    inline void cb_box_DEGRAD_i(StaticText *, void *);
    static void cb_box_DEGRAD(StaticText *, void *);
    StaticText *box_bracket;
    StaticText *box_M;
    inline void cb_box_M_i(StaticText *, void *);
    static void cb_box_M(StaticText *, void *);
    Fl_Button *radio_2;
    inline void cb_radio_2_i(Fl_Button *, void *);
    static void cb_radio_2(Fl_Button *, void *);
    Fl_Button *radio_8;
    inline void cb_radio_8_i(Fl_Button *, void *);
    static void cb_radio_8(Fl_Button *, void *);
    Fl_Button *radio_10;
    inline void cb_radio_10_i(Fl_Button *, void *);
    static void cb_radio_10(Fl_Button *, void *);
    Fl_Button *radio_16;
    inline void cb_radio_16_i(Fl_Button *, void *);
    static void cb_radio_16(Fl_Button *, void *);
    Fl_Button *but_7;
    inline void cb_but_7_i(Fl_Button *, void *);
    static void cb_but_7(Fl_Button *, void *);
    Fl_Button *but_8;
    inline void cb_but_8_i(Fl_Button *, void *);
    static void cb_but_8(Fl_Button *, void *);
    Fl_Button *but_9;
    inline void cb_but_9_i(Fl_Button *, void *);
    static void cb_but_9(Fl_Button *, void *);
    Fl_Button *but_4;
    inline void cb_but_4_i(Fl_Button *, void *);
    static void cb_but_4(Fl_Button *, void *);
    Fl_Button *but_5;
    inline void cb_but_5_i(Fl_Button *, void *);
    static void cb_but_5(Fl_Button *, void *);
    Fl_Button *but_6;
    inline void cb_but_6_i(Fl_Button *, void *);
    static void cb_but_6(Fl_Button *, void *);
    Fl_Button *but_1;
    inline void cb_but_1_i(Fl_Button *, void *);
    static void cb_but_1(Fl_Button *, void *);
    Fl_Button *but_2;
    inline void cb_but_2_i(Fl_Button *, void *);
    static void cb_but_2(Fl_Button *, void *);
    Fl_Button *but_3;
    inline void cb_but_3_i(Fl_Button *, void *);
    static void cb_but_3(Fl_Button *, void *);
    Fl_Button *but_0;
    inline void cb_but_0_i(Fl_Button *, void *);
    static void cb_but_0(Fl_Button *, void *);
    Fl_Button *but_dot;
    inline void cb_but_dot_i(Fl_Button *, void *);
    static void cb_but_dot(Fl_Button *, void *);
  public:
      Fl_Button * but_sign;
  private:
      inline void cb_but_sign_i(Fl_Button *, void *);
    static void cb_but_sign(Fl_Button *, void *);
    Fl_Button *but_C;
    inline void cb_but_C_i(Fl_Button *, void *);
    static void cb_but_C(Fl_Button *, void *);
    Fl_Button *but_AC;
    inline void cb_but_AC_i(Fl_Button *, void *);
    static void cb_but_AC(Fl_Button *, void *);
    Fl_Button *but_X;
    inline void cb_but_X_i(Fl_Button *, void *);
    static void cb_but_X(Fl_Button *, void *);
    Fl_Button *but_div;
    inline void cb_but_div_i(Fl_Button *, void *);
    static void cb_but_div(Fl_Button *, void *);
    Fl_Button *but_plus;
    inline void cb_but_plus_i(Fl_Button *, void *);
    static void cb_but_plus(Fl_Button *, void *);
    Fl_Button *but_minus;
    inline void cb_but_minus_i(Fl_Button *, void *);
    static void cb_but_minus(Fl_Button *, void *);
    Fl_Button *but_pi;
    inline void cb_but_pi_i(Fl_Button *, void *);
    static void cb_but_pi(Fl_Button *, void *);
    Fl_Button *but_eval;
    inline void cb_but_eval_i(Fl_Button *, void *);
    static void cb_but_eval(Fl_Button *, void *);
    Fl_Button *but_sqrt;
    inline void cb_but_sqrt_i(Fl_Button *, void *);
    static void cb_but_sqrt(Fl_Button *, void *);
    Fl_Button *but_pow;
    inline void cb_but_pow_i(Fl_Button *, void *);
    static void cb_but_pow(Fl_Button *, void *);
    Fl_Button *but_sin;
    inline void cb_but_sin_i(Fl_Button *, void *);
    static void cb_but_sin(Fl_Button *, void *);
    Fl_Button *but_cos;
    inline void cb_but_cos_i(Fl_Button *, void *);
    static void cb_but_cos(Fl_Button *, void *);
    Fl_Button *but_tan;
    inline void cb_but_tan_i(Fl_Button *, void *);
    static void cb_but_tan(Fl_Button *, void *);
    Fl_Button *but_log;
    inline void cb_but_log_i(Fl_Button *, void *);
    static void cb_but_log(Fl_Button *, void *);
    Fl_Button *but_ln;
    inline void cb_but_ln_i(Fl_Button *, void *);
    static void cb_but_ln(Fl_Button *, void *);
    Fl_Button *but_int;
    inline void cb_but_int_i(Fl_Button *, void *);
    static void cb_but_int(Fl_Button *, void *);
    Fl_Button *but_dr;
    inline void cb_but_dr_i(Fl_Button *, void *);
    static void cb_but_dr(Fl_Button *, void *);
    Fl_Button *but_drg;
    inline void cb_but_drg_i(Fl_Button *, void *);
    static void cb_but_drg(Fl_Button *, void *);
    Fl_Button *but_leftbr;
    inline void cb_but_leftbr_i(Fl_Button *, void *);
    static void cb_but_leftbr(Fl_Button *, void *);
    Fl_Button *but_rightbr;
    inline void cb_but_rightbr_i(Fl_Button *, void *);
    static void cb_but_rightbr(Fl_Button *, void *);
    Fl_Button *but_exch;
    inline void cb_but_exch_i(Fl_Button *, void *);
    static void cb_but_exch(Fl_Button *, void *);
    Fl_Button *but_invx;
    inline void cb_but_invx_i(Fl_Button *, void *);
    static void cb_but_invx(Fl_Button *, void *);
    Fl_Button *but_fact;
    inline void cb_but_fact_i(Fl_Button *, void *);
    static void cb_but_fact(Fl_Button *, void *);
    Fl_Button *but_Mplus;
    inline void cb_but_Mplus_i(Fl_Button *, void *);
    static void cb_but_Mplus(Fl_Button *, void *);
    Fl_Button *but_Mmult;
    inline void cb_but_Mmult_i(Fl_Button *, void *);
    static void cb_but_Mmult(Fl_Button *, void *);
    Fl_Button *but_Mclear;
    inline void cb_but_Mclear_i(Fl_Button *, void *);
    static void cb_but_Mclear(Fl_Button *, void *);
    Fl_Button *but_Mst;
    inline void cb_but_Mst_i(Fl_Button *, void *);
    static void cb_but_Mst(Fl_Button *, void *);
    Fl_Button *but_Mrc;
    inline void cb_but_Mrc_i(Fl_Button *, void *);
    static void cb_but_Mrc(Fl_Button *, void *);
    Fl_Button *check_inv;
    inline void cb_check_inv_i(Fl_Button *, void *);
    static void cb_check_inv(Fl_Button *, void *);
    Fl_Button *but_quit;
    inline void cb_but_quit_i(Fl_Button *, void *);
    static void cb_but_quit(Fl_Button *, void *);
  public:
    // ~SciCalc();
    void run(int px = -1, int py = -1);
  private:
    void handle_number(double numb);
    void handle_operator(Operator op);
    void change_base(int newbase);
    void set_display(double val, mode behind);
    void set_memdisp();
    void set_drgdisp();
    void set_brktdisp();
    void add_left_bracket();
    void add_right_bracket();
  public:
    void factorial();
    void exchange();
    void exponent_pi();
    void calc(int i);
  private:
    void init_value(int lev);
    void cvttobase(double num, int base, mode behind, char *str);
    void setnormlabels();
    void setinvlabels();
    void mem_exchange();
    double to_drg(double angle);
    double from_drg(double angle);
  public:
    void memexch();
  private:			// New members
    void ButtonGeometryInvalidate()
    {
	ButtonGeometryValid = FALSE;
    }
    void SetButtonWindowGeometry(int, int, int, int, int, int);

    int GetButtonPosX(int);
    int GetButtonPosY(int);
    int GetButtonWidth();
    int GetButtonHeight();
    inline void cb_to_sci_mode_i(Fl_Button *, void *);
    static void cb_to_sci_mode(Fl_Button *, void *);
    inline void cb_to_simple_mode_i(Fl_Button *, void *);
    static void cb_to_simple_mode(Fl_Button *, void *);
  public:
    virtual void resize_notify(int, int, int, int);
    void do_resize(int, int);
};
#endif
