import React from 'react';
import { makeStyles } from '@material-ui/core/styles';
import Drawer from '@material-ui/core/Drawer';
import List from '@material-ui/core/List';
import Divider from '@material-ui/core/Divider';
import ListItem from '@material-ui/core/ListItem';
import ListItemText from '@material-ui/core/ListItemText';
import Typography from '@material-ui/core/Typography';
import IconButton from '@material-ui/core/IconButton';
import Add from '@material-ui/icons/Add';
import { CreateWeather, CreateCuteness } from "../factory/action"

class MyListDrawer extends React.Component {
    classesDrawer = makeStyles(theme => ({
        list: {
            width: 250,
        },
        fullList: {
            width: 'auto',
        },
        menuButton: {
            marginRight: theme.spacing(2),
        },
        title: {
            flexGrow: 1,
        },
    }));
    state = {
        left: false,
    }
    toggleDrawer = (side, open) => event => {
        if (event.type === 'keydown' && (event.key === 'Tab' || event.key === 'Shift')) {
            return;
        }
        this.setState({ ...this.state, [side]: open });
    };
    sideList = side => (
        <div className={this.classesDrawer.list} role="presentation" onClick={this.toggleDrawer(side, false)} onKeyDown={this.toggleDrawer(side, false)} >
            <List>
                <ListItem>
                    <Typography variant="h6" className={this.classesDrawer.title} style={{ textAlign: 'center' }}>
                    Services
                    </Typography>
                </ListItem>
            </List>
            <Divider />
            <List>
                <ListItem button key={"Weather"}>
                    <ListItemText primary={"Weather"} style={{ textAlign: 'center' }} onClick={() => this.props.createW(CreateWeather())} />
                </ListItem>
                <ListItem button key={"Cuteness"}>
                    <ListItemText primary={"Cuteness"} style={{ textAlign: 'center' }} onClick={() => this.props.createW(CreateCuteness())} />
                </ListItem>
            </List>
        </div>
    );
    render() {
        return (
            <div>
                <IconButton edge="start" className={this.classesDrawer.menuButton} color="inherit" aria-label="menu" onClick={this.toggleDrawer('left', true)}>
                    <Add />
                </IconButton>
                <Drawer open={this.state.left} onClose={this.toggleDrawer('left', false)}>
                    {this.sideList('left')}
                </Drawer>
            </div>
        );
    }
}

export default MyListDrawer