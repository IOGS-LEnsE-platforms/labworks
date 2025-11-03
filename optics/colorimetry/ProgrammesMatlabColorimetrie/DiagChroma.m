function varargout = DiagChroma(varargin)
% DIAGCHROMA MATLAB code for DiagChroma.fig
%      DIAGCHROMA, by itself, creates a new DIAGCHROMA or raises the existing
%      singleton*.
%
%      H = DIAGCHROMA returns the handle to a new DIAGCHROMA or the handle to
%      the existing singleton*.
%
%      DIAGCHROMA('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in DIAGCHROMA.M with the given input arguments.
%
%      DIAGCHROMA('Property','Value',...) creates a new DIAGCHROMA or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before DiagChroma_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to DiagChroma_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help DiagChroma

% Last Modified by GUIDE v2.5 11-Jul-2017 12:55:10

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @DiagChroma_OpeningFcn, ...
                   'gui_OutputFcn',  @DiagChroma_OutputFcn, ...
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


% --- Executes just before DiagChroma is made visible.
function DiagChroma_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to DiagChroma (see VARARGIN)

% Choose default command line output for DiagChroma
handles.output = hObject;
% Update handles structure
guidata(hObject, handles);
GraphSpectrumLocusb;
% UIWAIT makes DiagChroma wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = DiagChroma_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes during object creation, after setting all properties.
function AxesChroma_CreateFcn(hObject, eventdata, handles)
% hObject    handle to AxesChroma (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: place code in OpeningFcn to populate AxesChroma



function AfficheX1_Callback(hObject, eventdata, handles)
% hObject    handle to AfficheX1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of AfficheX1 as text
%        str2double(get(hObject,'String')) returns contents of AfficheX1 as a double
 

% --- Executes during object creation, after setting all properties.
function AfficheX1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to AfficheX1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function AfficheY1_Callback(hObject, eventdata, handles)
% hObject    handle to AfficheY1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of AfficheY1 as text
%        str2double(get(hObject,'String')) returns contents of AfficheY1 as a double


% --- Executes during object creation, after setting all properties.
function AfficheY1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to AfficheY1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function Legende1_Callback(hObject, eventdata, handles)
% hObject    handle to Legende1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Legende1 as text
%        str2double(get(hObject,'String')) returns contents of Legende1 as a double


% --- Executes during object creation, after setting all properties.
function Legende1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Legende1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end




% --- Executes on button press in Ajouter.
function Ajouter_Callback(hObject, eventdata, handles)
% hObject    handle to Ajouter (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if get(hObject,'Value')
x1=str2double(get(handles.AfficheX1,'String'));
y1=str2double(get(handles.AfficheY1,'String'));
% z1=1-(x1+y1);
%  rgb=xyz2rgb([x1 y1 z1]);
%  for i=1:3 
%      if rgb(i)<0, rgb(i)=0;
%      end
%  end
 
Leg1=get(handles.Legende1,'String');
plot(handles.AxesChroma, x1,y1,'xr','LineWidth',4) %'Color',rgb), 
text(x1+0.02,y1+0.02,Leg1);    
end


% --- Executes on button press in Effacer.
function Effacer_Callback(hObject, eventdata, handles)
% hObject    handle to Effacer (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
cla(handles.AxesChroma)


