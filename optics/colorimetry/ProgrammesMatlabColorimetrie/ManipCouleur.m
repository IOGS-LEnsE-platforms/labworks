function varargout = ManipCouleur(varargin)
% MANIPCOULEUR MATLAB code for ManipCouleur.fig
%      MANIPCOULEUR, by itself, creates a new MANIPCOULEUR or raises the existing
%      singleton*.
%
%      H = MANIPCOULEUR returns the handle to a new MANIPCOULEUR or the handle to
%      the existing singleton*.
%
%      MANIPCOULEUR('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in MANIPCOULEUR.M with the given input arguments.
%
%      MANIPCOULEUR('Property','Value',...) creates a new MANIPCOULEUR or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before ManipCouleur_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to ManipCouleur_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help ManipCouleur

% Last Modified by JM 15/09/2017 : modification pour n'avoir que des
% valeurs entières

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @ManipCouleur_OpeningFcn, ...
                   'gui_OutputFcn',  @ManipCouleur_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before ManipCouleur is made visible.
function ManipCouleur_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to ManipCouleur (see VARARGIN)

% Choose default command line output for ManipCouleur
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);
global s 
if isempty(s)
    s = serial('COM10'); %valeur par défaut
    set(handles.MenuPort,'Value',10);

end;


% UIWAIT makes ManipCouleur wait for user response (see UIRESUME)
% uiwait(handles.figure1);

% --- Outputs from this function are returned to the command line.
function varargout = ManipCouleur_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%  BOITE A LUMIERE
%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%


function MaJLEDs_CreateFcn(hObject, eventdata, handles)


% --- Executes on button press in MaJLEDs.
function MaJLEDs_Callback(hObject, eventdata, handles)
global s
% Lecture des valeurs des commandes des 5 LED
REF1str=get(handles.AffichageValeurREF1,'String');
REF2str=get(handles.AffichageValeurREF2,'String');
Rstr=get(handles.AffichageValeurR,'String');
Vstr=get(handles.AffichageValeurV,'String');
Bstr=get(handles.AffichageValeurB,'String');

% Envoi de ces commandes (séparées par un espace)
% à la carte Arduino

fopen(s);
pause(2)
fprintf(s,Rstr);
fprintf(s,' ');
fprintf(s,Vstr);
fprintf(s,' ');
fprintf(s,Bstr);
fprintf(s,' ');
fprintf(s,REF1str);
fprintf(s,' ');
fprintf(s,REF2str);
fprintf(s,'\n');
fclose(s);



%%%%%%%%%%%% LEDs de référence

% --- Executes on slider movement.
function SliderValeurREF1_Callback(hObject, eventdata, handles)
% hObject    handle to SliderValeurREF1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'Value') returns position of slider
%        get(hObject,'Min') and get(hObject,'Max') to determine range of slider
ValeurREF1=round(get(hObject,'Value'));
set(handles.AffichageValeurREF1,'String', ValeurREF1);
% Mise à jour de l'affichage si slider modifié


% --- Executes during object creation, after setting all properties.
function SliderValeurREF1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to SliderValeurREF1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end

function AffichageValeurREF1_Callback(hObject, eventdata, handles)
% hObject    handle to AffichageValeurREF1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of AffichageValeurREF1 as text
%        str2double(get(hObject,'String')) returns contents of AffichageValeurREF1 as a double

ValeurREF1=round(str2double(get(hObject,'String')));
set(handles.SliderValeurREF1,'Value',ValeurREF1);
% Mise à jour du slider si valeur affichée modifiée directement

% --- Executes during object creation, after setting all properties.
function AffichageValeurREF1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to AffichageValeurREF1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

function SliderValeurREF2_Callback(hObject, eventdata, handles)
% Mise à jour de l'affichage si slider modifié
ValeurREF2=round(get(hObject,'Value'));
set(handles.AffichageValeurREF2,'String', ValeurREF2);

function SliderValeurREF2_CreateFcn(hObject, eventdata, handles)
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end

function AffichageValeurREF2_Callback(hObject, eventdata, handles)
% Mise à jour du slider si valeur affichée modifiée directement
ValeurREF2=round(str2double(get(hObject,'String')));
set(handles.SliderValeurREF2,'Value',ValeurREF2);

function AffichageValeurREF2_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

%%%%%%%%%%%% LED trichrome
% LED R
function SliderValeurR_Callback(hObject, eventdata, handles)
% Mise à jour de l'affichage si slider modifié
ValeurR=round(get(hObject,'Value'));
set(handles.AffichageValeurR,'String', ValeurR);


function SliderValeurR_CreateFcn(hObject, eventdata, handles)
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end

function AffichageValeurR_Callback(hObject, eventdata, handles)
ValeurR=round(str2double(get(hObject,'String')));
set(handles.SliderValeurR,'Value',ValeurR);

function AffichageValeurR_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% LED V

function SliderValeurV_Callback(hObject, eventdata, handles)
% Mise à jour de l'affichage si slider modifié
ValeurV=round(get(hObject,'Value'));
set(handles.AffichageValeurV,'String', ValeurV);


function SliderValeurV_CreateFcn(hObject, eventdata, handles)

if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end

function AffichageValeurV_Callback(hObject, eventdata, handles)
ValeurV=round(str2double(get(hObject,'String')));
set(handles.SliderValeurV,'Value',ValeurV);

function AffichageValeurV_CreateFcn(hObject, eventdata, handles)

if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

% LED B

function SliderValeurB_CreateFcn(hObject, eventdata, handles)
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end

function SliderValeurB_Callback(hObject, eventdata, handles)
% Mise à jour de l'affichage si slider modifié
ValeurB=round(get(hObject,'Value'));
set(handles.AffichageValeurB,'String', ValeurB);

function AffichageValeurB_CreateFcn(hObject, eventdata, handles)

if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

function AffichageValeurB_Callback(hObject, eventdata, handles)
ValeurB=round(str2double(get(hObject,'String')));
set(handles.SliderValeurB,'Value',ValeurB);



function MenuPort_Callback(hObject, eventdata, handles)

contents = cellstr(get(hObject,'String'));
contents{get(hObject,'Value')};
global s 
fclose(s);
delete s;
s = serial(contents{get(hObject,'Value')}); 
fopen(s);
pause(2);




function MenuPort_CreateFcn(hObject, eventdata, handles)

if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes during object creation, after setting all properties.
function figure1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called
