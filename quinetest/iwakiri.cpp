#include <iostream>
#include <string>
#include <string_view>
#include <regex>

using namespace std::string_literals;

std::string encoded = R"(
#include$SPACE<iostream>$NEWLINE#include$SPACE<string>$NEWLINE#include$SPACE<string_view>$NEWLINE#include$SPACE<regex>$NEWLINE$NEWLINEusing$SPACEnamespace$S
PACEstd::string_literals;$NEWLINE$NEWLINEstd::string$SPACEencoded$SPACE=$SPACE{}{}{};$NEWLINEstd::string$SPACERemoveSpace(const$SPACEstd::string&$SPACEstr){
return$SPACEstd::regex_replace(str,$SPACEstd::regex("$SPACE"),$SPACE"");}$SPACEstd::string$SPACERemoveNewLine(const$SPACEstd::string&$SPACEstr){$NEWLINEretu
rn$SPACEstd::regex_replace(str,$SPACEstd::regex("\n"),$SPACE"");}std::string$SPACERestoreString(std::string$SPACEstr){static$SPACEconst$SPACEstd::string$SPA
                 CE                                                                                                                     SPA                 
                CE_T                        OKE                                                                                         N$S                 
   PAC          E=$S          PAC           E"\                                                                                         \$"                 
   s$S          PACE          +$S           PAC                                                                           E"SPACE";$SPACE$NEWLINEstatic$SP  
   ACE          cons          t$S           PAC       Estd::string$SPACETAB_                                             TOKEN$SPACE=$SPACE"\\$"s$SPACE+$SP 
   ACE          "TAB          ";$           SPA       CEstatic$SPACEconst$S                                              PACEstd::string$SPACENEWLINE_TOKEN 
   $SP          ACE=          $SP           ACE       "\\$"s$SPACE+$SPACE"N                                                             EWL                 
   INE          ";st          ati           c$S              PAC        Eco                                                             nst                 
   $SPACEstd::string$SPACESPACE_C           HAR              ACT        ER$                                                             SPA                 
   CE=$SPACE"$SPACE";$NEWLINEstat           ic$              SPA        CEc                                                   onst$SPACEstd::string$SP      
   ACETAB_CHARACTERS$SPACE=$SPACE           "$T      AB"     ;$S        PAC                                                   Estatic$SPACEconst$SPACE      
                                            std ::string     $SP        ACE                                                   NEW                  LIN      
                                           E_CHARACTERS$     SPA        CE=                                                   $SP                  ACE      
                                        "\n";$SPACEst        r$S        PAC                                                   E=$                  SPA      
                                       CEstd::re             gex        _re                                                   place(str,$SPACEstd::reg      
ex(SPACE_TOKEN),$SPACESPACE_CHARACTE    R);$NEW              LIN        Est                                                   r$SPACE=$SPACEstd::regex      
_replace(str,$SPACEstd::regex(TAB_TO        KEN              ),$        SPA                                                   CET                  AB_      
CHARACTERS);$SPACEstr$SPACE=$SPACEst        d::             reg         ex_     replace(str,$SPACEstd::regex(NEWLINE          _TO                  KEN      
           ),$                              SPA             CEN         EWL     INE_CHARACTERS);return$SPACEstr;}$SP          ACE$NEWLINEstd::string$S      
          PACE                              Min             iFo         rma     t(std::string_view$SPACEcontent,$SPA          CEstd::string$SPACEarg,$      
         SPAC                               Esi             ze_         t$S                                                   PAC                  Ein      
         dex                                $SP             ACE         =$S                                                   PAC                  E0)      
        {aut                                o$S      PA    CEfo         rma                                                   tPo                  int      
       $SPACE=$SPACEcontent.find(           "{}      ");   for          (si                                                   ze_t$SPACEi$SPACE=$SPACE      
      0;$SPACEi$SPACE<$SPACEindex           ;$S      PAC   E++          i){                                                   $NEWLINEformatPoint$SPAC      
     E=$SPACEcontent.find("{}",$S           PAC      Efo   rma          tPo                                                                                 
    int$SPA                   CE+           $SP      AC   E1)           ;}a                                                                                 
   uto$ SPA                   CEf           ormer$SPACE   =$S          PACE                                              content.substr(0,$SPACEformatPoint 
 );aut  o$S                   PAC            Elatter$SP  ACE=          $SPA                                             CEcontent.substr(formatPoint$SPACE+$
SPACE   2);                   ret            urn$SPACE   std           ::s                                              tring$NEWLINE{former}$SPACE+$SPACEar
g$SP    ACE                   +$S                       PACE           std                                                                                  
::      str                   ing                      {lat            ter                                                         };          }in          
        t$S                   PAC                     Emai             n()                                                       {auto        $SPACE        
        decoded$SPACE=$SPACEResto                    reSt             ring                                                    (Remove          Space(Re     
        moveNewLine(encoded)));st                  d::str      ing$SPACEo                                                   utStrin               g;outSt   
        ring$SPACE=$SPACEMiniForm                  at($         NEWLINEde                                                coded,$S                   PACE"R\ 
        "("                   );o                   ut          String$                                                  SPACE                         =$SP 
        ACE                   Min                                                                                         i                              F  
ormat(outString,$SPACE")\"",$SPACE1);outString$SPACE=$SPACEMiniFormat(outString,$SPACEencoded);std::cout$SPACE<<$SPACEoutString;}$NEWLINE)";
std::string RemoveSpace(const std::string& str){return std::regex_replace(str, std::regex(" "), "");} std::string RemoveNewLine(const std::string& str){
return std::regex_replace(str, std::regex("\n"), "");}std::string RestoreString(std::string str){static const std::string SPACE_TOKEN = "\\$"s + "SPACE"; 
static const std::string TAB_TOKEN = "\\$"s + "TAB"; static const std::string NEWLINE_TOKEN = "\\$"s + "NEWLINE";static const std::string SPACE_CHARACTER = " ";
static const std::string TAB_CHARACTERS = "    "; static const std::string NEWLINE_CHARACTERS = "\n"; str = std::regex_replace(str, std::regex(SPACE_TOKEN), SPACE_CHARACTER);
str = std::regex_replace(str, std::regex(TAB_TOKEN), TAB_CHARACTERS); str = std::regex_replace(str, std::regex(NEWLINE_TOKEN), NEWLINE_CHARACTERS);return str;} 
std::string MiniFormat(std::string_view content, std::string arg, size_t index = 0){auto formatPoint = content.find("{}");for(size_t i = 0; i < index; ++i){
formatPoint = content.find("{}", formatPoint + 1);}auto former = content.substr(0, formatPoint);auto latter = content.substr(formatPoint + 2);return std::string
{former} + arg + std::string{latter};}int main(){auto decoded = RestoreString(RemoveSpace(RemoveNewLine(encoded)));std::string outString;outString = MiniFormat(
decoded, "R\"(");outString = MiniFormat(outString, ")\"", 1);outString = MiniFormat(outString, encoded);std::cout << outString;}
