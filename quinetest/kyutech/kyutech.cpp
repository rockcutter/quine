#include <iostream>
#include <string>
#include <string_view>
#include <regex>

using namespace std::string_literals;

std::string encoded = R"(
#include$SPACE<iostream>$NEWLINE#include$SPACE<string>$NEWLINE#include$SPACE<string_view>$NEWLINE#includ
e$SPACE<regex>$NEWLINE$NEWLINEusing$SPACEnamespace$SPACEstd::string_literals;$NEWLINE$NEWLINEstd::string
$S   PACEencoded$SPACE=$SPACE{}{}{};$NEWLINEstd::string$SPACERemoveSpace(const$SPACEstd::str   ing&$SPAC
Es   tr){return$SPACEstd::regex_replace(str,$SPACEstd::regex("$SPACE"),$SPACE"");}$NEWLINEst   d::string
$S   PACERemoveNewLine(const$SPACEstd::string&$SPACE str){return$SPACEstd::regex_replace(str   ,$SPACEst
d:   :regex("\n"),$SPACE"");}$NEWLINEstd::string$SP  ACERestoreString(std::string$SPACEstr){   static$SP
AC   Econst$SPACEstd::string$SPACESPACE_TOKEN$SPAC   E=$SPACE"\\$"s$SPACE+$SPACE"SPACE";$SPA   CE$NEWLIN
Es   tatic$SPACEconst$SPACEstd::string$SPACETAB_TO   KEN$SPACE=$SPACE"\\$"s$SPACE+$SPACE"TAB   ";$SPACEs
td   ::string$SPACENEWLINE_TOKEN$SPACE=$SPACE"\\$"   s$SPACE+$SPACE"NEWLINE";$NEWLINEstatic$   SPACEcons
t$   SPACEstd::string$SPACESPACE_CHARACTER$SPACE=$   SPACE"$SPACE";$SPACEstatic$SPACEconst$S   PACEstd::
st   ring$  SPAC   ETAB_CH  ARAC   TERS$  SPACE          =$SPACE"    $SPACE$SPACE    $SPACE$   SP   ACE"
;$   SPAC   E$NEW  LINEst   atic   $SPAC  Econs          t$SPACE       std::str        ing$S         PAC
EN   EWL   INE_CH   ARACT   ERS$   SPACE  =$SPACE"   \n";$SPACE   st   r$SPACE    =$   SPACE     st   d:
:r   eg   ex_repl   ace(s  tr,$S   PACEs  td::rege   x(SPACE_TO  KEN$   NEWLIN   E),SP ACE_C    HARA  CT
ER   );   str$SPAC  E=$S   PACEs   td::r  egex_rep   lace(str,   $SPA   CEstd   ::regex(TAB_   TOKEN  ),
$S   P   ACETAB_CH   ARA   CTERS   );$SP  ACEstr$S   PACE=$NEW   LINEs  td::r   egex_replace   (str,  st
d:      :regex(NEW   LIN  E_TOKE   N),NE  WLINE_CH   ARACTERS)  ;retur  n$SPA  CEstr;}std::s   tring  $S
PA       CEMiniForm  at   ($NEWL   INEst  d::strin   g_view$SP          ACEco  ntent,std::st   ring$  SP
AC    E  arg,$SPACE   s   ize_t$   SPACE  index$SP   ACE=$SPAC          E0){a  uto$SPACEform   atPoi  nt
$S   PA   CE=$SPACEc  o  ntent.f   ind("  {}");for   ($NEWLINE  size_t$SPACEi  $SPACE=$SPACE   0;$SP  AC
Ei   $SP  ACE<$SPACE  i  ndex;$S   PACE+  +i){form   atPoint$S  PACE=$SPACEco  ntent.find("{   }",$S  PA
CE   for   matPoint$    SPACE+$S   PACE1  );}auto$   SPACEform  er$SPACE=$SPA   CE$NEWLINEco   ntent  .s
ub   str(  0,$SPACEfo   rmatPoin   t);a   uto$SPAC   Elatter$S   PACE=$SPACEc   ontent.subst   r(for  ma
tP   oint   $SPACE+$S   PACE2);r   etur   n$SPACEs   td::string  {form  er}$N   EWLINE +$SPA   CEarg  $S
PA   CE+$   SPACEstd:  :string{la   tt    er};}$SPA  CEint$SPAC   Ema   in(){a   uto    $SPA   CEdec  od
ed   $SPAC   E=$SPAC   ERestoreSt      r  ing(Remov     eSpace(R       emoveNew        Line(   encod  ed
)$   NEWLI   NE));st   d::string$S    PA  CEoutStri     ng;outStr     ing$SPACE=      $SPACE   MiniF  or
mat(decoded,$SPAC     E"R\"(");outString$SPACE=$SPACEMiniFormat(outString,$SPACE")\""$NEWLINE,1);outStri
ng$SPACE=$SPACEMi    niFormat(outString,$SPACEencoded);std::cout$SPACE<<$SPACEoutString;})";
std::string RemoveSpace(const std::string& str){return std::regex_replace(str, std::regex(" "), "");}
std::string RemoveNewLine(const std::string& str){return std::regex_replace(str, std::regex("\n"), "");}
std::string RestoreString(std::string str){static const std::string SPACE_TOKEN = "\\$"s + "SPACE"; 
static const std::string TAB_TOKEN = "\\$"s + "TAB"; std::string NEWLINE_TOKEN = "\\$"s + "NEWLINE";
static const std::string SPACE_CHARACTER = " "; static const std::string TAB_CHARACTERS = "    "; 
static const std::string NEWLINE_CHARACTERS = "\n"; str = std::regex_replace(str, std::regex(SPACE_TOKEN
),SPACE_CHARACTER);str = std::regex_replace(str, std::regex(TAB_TOKEN), TAB_CHARACTERS); str =
std::regex_replace(str,std::regex(NEWLINE_TOKEN),NEWLINE_CHARACTERS);return str;}std::string MiniFormat(
std::string_view content,std::string arg, size_t index = 0){auto formatPoint = content.find("{}");for(
size_t i = 0; i < index; ++i){formatPoint = content.find("{}", formatPoint + 1);}auto former = 
content.substr(0, formatPoint);auto latter = content.substr(formatPoint + 2);return std::string{former}
+ arg + std::string{latter};} int main(){auto decoded = RestoreString(RemoveSpace(RemoveNewLine(encoded)
));std::string outString;outString = MiniFormat(decoded, "R\"(");outString = MiniFormat(outString, ")\""
,1);outString = MiniFormat(outString, encoded);std::cout << outString;}