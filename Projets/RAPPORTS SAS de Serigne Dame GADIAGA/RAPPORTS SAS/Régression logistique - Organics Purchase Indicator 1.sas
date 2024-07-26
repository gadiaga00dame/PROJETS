/*---------------------------------------------------------
  L’instruction Options ci-dessous doit être placée
 avant l’étape DATA lors de la soumission du code.
---------------------------------------------------------*/
options VALIDMEMNAME=EXTEND VALIDVARNAME=ANY;
   /*------------------------------------------
   Code de scoring SAS généré
     Date                 : 22Apr2024:18:50:52
     Paramètres régionaux : fr_FR
     Type du modèle       : Régression logistique
     Variable quantitative: DemAffl(Affluence Grade)
     Variable quantitative: PromSpend(Total Spend)
     Variable quantitative: DemAge(Age)
     Variable qualitative : DemReg(Geographic Region)
     Variable qualitative : PromClass(Loyalty Status)
     Variable qualitative : _va_c_sexe(sexe)
     Variable qualitative : DemTVReg(Television Region)
     Variable qualitative : TargetBuy(Organics Purchase Indicator)
     Variable de réponse  : TargetBuy(Organics Purchase Indicator)
     Distribution         : Binaire
     Fonction de liaison  : Logit
     ------------------------------------------*/
/* Colonne calculée temporaire */
length '_va_c_sexe'n $5;
if (('DemGender'n IN ('F')))then do;
'_va_c_sexe'n= 'F';
end;
else do;
if (('DemGender'n IN ('M')))then do;
'_va_c_sexe'n= 'M';
end;
else do;
if (('DemGender'n IN (' ','U')))then do;
'_va_c_sexe'n= 'U';
end;
else do;
'_va_c_sexe'n= 'Autre';
end;
end;
end;
;

/*------------------------------------------*/
   /*---------------------------------------------------------
     Code SAS pour le scoring généré
     Date: 22 avril 2024 18 h 50
     -------------------------------------------------------*/

   /*---------------------------------------------------------
   Defining temporary arrays and variables   
     -------------------------------------------------------*/
   drop _badval_ _linp_ _temp_ _i_ _j_;
   _badval_ = 0;
   _linp_   = 0;
   _temp_   = 0;
   _i_      = 0;
   _j_      = 0;
   drop MACLOGBIG;
   MACLOGBIG= 7.0978271289338392e+02;

   array _xrow_1185_0_{29} _temporary_;
   array _beta_1185_0_{29} _temporary_ (   -1.92976065221378
          -0.08592992925207
          -0.28060749284662
          -0.07545977387067
          -0.15508372323383
                          0
           0.05228353186548
          -0.14446309995495
          -0.00818160134133
                          0
           1.79703984487837
           0.83650606170458
                          0
           -0.1606414344221
          -0.08117575100962
           0.03268668925909
           0.03460521526891
          -0.03344604430245
           0.28004820849727
                          0
           0.02374125987446
                          0
                          0
          -0.15234521114389
                          0
                          0
           0.25523506989083
        -9.4379324005442E-7
          -0.05357615720753);

   length _DemTVReg_ $18; drop _DemTVReg_;
   _DemTVReg_ = left(trim(put(DemTVReg,$18.)));
   length _PromClass_ $12; drop _PromClass_;
   _PromClass_ = left(trim(put(PromClass,$12.)));
   length __va_c_sexe_ $5; drop __va_c_sexe_;
   __va_c_sexe_ = left(trim(put(_va_c_sexe,$5.)));
   length _DemReg_ $15; drop _DemReg_;
   _DemReg_ = left(trim(put(DemReg,$15.)));
   /*------------------------------------------*/
   /*Missing values in model variables result  */
   /*in missing values for the prediction.     */
   if missing(PromSpend) 
      or missing(DemAge) 
      or missing(DemAffl) 
      then do;
         _badval_ = 1;
         goto skip_1185_0;
   end;
   /*------------------------------------------*/

   do _i_=1 to 29; _xrow_1185_0_{_i_} = 0; end;

   _xrow_1185_0_[1] = 1;

   _temp_ = 1;
   select (_DemReg_);
      when ('Midlands') _xrow_1185_0_[2] = _temp_;
      when ('North') _xrow_1185_0_[3] = _temp_;
      when ('Scottish') _xrow_1185_0_[4] = _temp_;
      when ('South East') _xrow_1185_0_[5] = _temp_;
      when ('South West') _xrow_1185_0_[6] = _temp_;
      otherwise do; _badval_ = 1; goto skip_1185_0; end;
   end;

   _temp_ = 1;
   select (_PromClass_);
      when ('Gold') _xrow_1185_0_[7] = _temp_;
      when ('Platinum') _xrow_1185_0_[8] = _temp_;
      when ('Silver') _xrow_1185_0_[9] = _temp_;
      when ('Tin') _xrow_1185_0_[10] = _temp_;
      otherwise do; _badval_ = 1; goto skip_1185_0; end;
   end;

   _temp_ = 1;
   select (__va_c_sexe_);
      when ('F') _xrow_1185_0_[11] = _temp_;
      when ('M') _xrow_1185_0_[12] = _temp_;
      when ('U') _xrow_1185_0_[13] = _temp_;
      otherwise do; _badval_ = 1; goto skip_1185_0; end;
   end;

   _temp_ = 1;
   select (_DemTVReg_);
      when ('Border') _xrow_1185_0_[14] = _temp_;
      when ('C Scotland') _xrow_1185_0_[15] = _temp_;
      when ('East') _xrow_1185_0_[16] = _temp_;
      when ('London') _xrow_1185_0_[17] = _temp_;
      when ('Midlands') _xrow_1185_0_[18] = _temp_;
      when ('N East') _xrow_1185_0_[19] = _temp_;
      when ('N Scot') _xrow_1185_0_[20] = _temp_;
      when ('N West') _xrow_1185_0_[21] = _temp_;
      when ('S & S East') _xrow_1185_0_[22] = _temp_;
      when ('S West') _xrow_1185_0_[23] = _temp_;
      when ('Ulster') _xrow_1185_0_[24] = _temp_;
      when ('Wales & West') _xrow_1185_0_[25] = _temp_;
      when ('Yorkshire') _xrow_1185_0_[26] = _temp_;
      otherwise do; _badval_ = 1; goto skip_1185_0; end;
   end;

   _xrow_1185_0_[27] = DemAffl;

   _xrow_1185_0_[28] = PromSpend;

   _xrow_1185_0_[29] = DemAge;

   do _i_=1 to 29;
      _linp_ + _xrow_1185_0_{_i_} * _beta_1185_0_{_i_};
   end;

   skip_1185_0:
   length I_TargetBuy $1;
   label I_TargetBuy = 'Dans : TargetBuy';
   array _levels_1185_{2} $ 1 _TEMPORARY_ ('1'
   ,'0'
   );
   label P_TargetBuy1 = 'Prédit : TargetBuy=1';
   if (_badval_ eq 0) and not missing(_linp_) then do;
      if (_linp_ > 0) then do;
         P_TargetBuy1 = 1 / (1+exp(-_linp_));
      end; else do;
         P_TargetBuy1 = exp(_linp_) / (1+exp(_linp_));
      end;
      P_TargetBuy0 = 1 - P_TargetBuy1;
      if P_TargetBuy1 >= 0.5                  then do;
         I_TargetBuy = _levels_1185_{1};
      end; else do;
         I_TargetBuy = _levels_1185_{2};
      end;
   end; else do;
      _linp_ = .;
      P_TargetBuy1 = .;
      P_TargetBuy0 = .;
      I_TargetBuy = ' ';
   end;
   /*------------------------------------------*/
   /*_VA_DROP*/ drop '_va_c_sexe'n 'I_TargetBuy'n 'P_TargetBuy1'n 'P_TargetBuy0'n;
length 'I_TargetBuy_1185'n $32;
      'I_TargetBuy_1185'n='I_TargetBuy'n;
'P_TargetBuy1_1185'n='P_TargetBuy1'n;
'P_TargetBuy0_1185'n='P_TargetBuy0'n;
   /*------------------------------------------*/